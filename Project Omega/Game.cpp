#include "Game.h"

// Static functions


void Game::initVariables()
{
    this->window = NULL;
    this->fullscreen = false;
    this->dt = 0.f;
}

// Initializer functions
void Game::initWindow()
{
    /* Creates a SFML window using options from a window.ini file */

    std::ifstream ifs("Config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();

    std::string title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned framerate_limit = 144;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> fullscreen;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
        ifs >> antialiasing_level;
    }

    ifs.close(); // Close the window.ini file

    this->fullscreen = fullscreen;
    this->windowSettings.antialiasingLevel = antialiasing_level;

    if (this->fullscreen) 
    {
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
    } 
    else
    {
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);
    }

    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys()
{
    std::ifstream ifs("Config/supported_keys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();

    this->supportedKeys["Escape"] = sf::Keyboard::Escape;
    this->supportedKeys["A"] = sf::Keyboard::A;
    this->supportedKeys["D"] = sf::Keyboard::D;
    this->supportedKeys["W"] = sf::Keyboard::W;
    this->supportedKeys["S"] = sf::Keyboard::S;

    // DEBUG REMOVE LATER
    for (auto i : this->supportedKeys)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
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
