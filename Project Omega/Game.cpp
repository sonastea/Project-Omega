#include "Game.h"

// Static functions


// Initializer functions
void Game::initWindow()
{
    /* Creates a SFML window using options from a window.ini file */

    std::ifstream ifs("Config/window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(1280, 720);
    unsigned framerate_limit = 144;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close(); // Close the window.ini file

	this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys()
{
    this->supportedKeys.emplace("Escape",   sf::Keyboard::Key::Escape);
    this->supportedKeys.emplace("A",        sf::Keyboard::Key::A);
    this->supportedKeys.emplace("D",        sf::Keyboard::Key::D);
    this->supportedKeys.emplace("W",        sf::Keyboard::Key::W);
    this->supportedKeys.emplace("S",        sf::Keyboard::Key::S);

    std::cout << this->supportedKeys.at("A") << "\n";
}

void Game::initStates()
{
    this->states.push(new GameState(this->window, &this->supportedKeys));
}


// Constructors/Destructors

Game::Game()
{
    this->initWindow(); // Calls window when Game object created
    this->initKeys(); // Key binds
    this->initStates(); // Init game states
}

Game::~Game()
{
    delete this->window; // RenderWindow pointer

    while (!this->states.empty()) // State pointer
    {
        delete this->states.top(); // Removes data in pointer
        this->states.pop(); // Removes actual pointers
    }
}

// Functions

void Game::endApplication()
{
    std::cout << "Ending Application!" << "\n";
}

void Game::updateDt()
{
    /* Updates the dt variable with thte time it takes to update and render one frame*/
    this->dt = this->dtClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed) 
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty()) 
    { 
        this->states.top()->update(this->dt); 

        if (this->states.top()->getQuit()) // Quit state conditional
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    // Application end
    else
    {
        this->endApplication();
        this->window->close();
    }

    
}

void Game::render()
{
    this->window->clear();

    // Render items
    if (!this->states.empty()) { this->states.top()->render(); }

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
