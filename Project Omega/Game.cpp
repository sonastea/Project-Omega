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

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

// Constructors/Destructors

Game::Game()
{
    this->initWindow(); // Calls window when Game object created
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

    if (!this->states.empty()) { this->states.top()->update(this->dt); }
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
