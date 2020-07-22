#include "stdafx.h"
#include "Game.h"

// Static functions

void Game::initVariables()
{
    this->window = NULL;

    this->dt = 0.f;

    *this->gridSize = 64.f;
}

void Game::initGraphicsSettings()
{
    this->gfxSettings.loadFromFile("Config/graphics.ini");
}

// Initializer functions
void Game::initWindow()
{
    /* Creates a SFML window using options from a window.ini file */
    if (this->gfxSettings.fullscreen) 
    {
        this->window = new sf::RenderWindow(
            this->gfxSettings.resolution, 
            this->gfxSettings.title, 
            sf::Style::Fullscreen,
            this->gfxSettings.contextSettings);
    } 
    else
    {
        this->window = new sf::RenderWindow(
            this->gfxSettings.resolution,
            this->gfxSettings.title,
            sf::Style::Titlebar | sf::Style::Close, 
            this->gfxSettings.contextSettings);
    }

    this->window->setFramerateLimit(this->gfxSettings.frameRateLimit);
    this->window->setVerticalSyncEnabled(this->gfxSettings.verticalSync);
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

void Game::initStateData()
{
    this->stateData.window = this->window;
    this->stateData.gfxSettings = &this->gfxSettings;
    this->stateData.supportedKeys = &this->supportedKeys;
    this->stateData.states = &this->states;
    this->stateData.gridSize = *this->gridSize;
}

void Game::initStates()
{
    this->states.push(new MainMenuState(&this->stateData));
}


// Constructors/Destructors

Game::Game()
{
    this->initVariables();
    this->initGraphicsSettings();
    this->initWindow(); // Calls window when Game object created
    this->initKeys(); // Key binds    
    this->initStateData();
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

    delete this->gridSize;
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

    if (!this->states.empty()) //&& this->window->hasFocus()) 
    {
        if (this->window->hasFocus())
        {
            this->states.top()->update(this->dt);

            if (this->states.top()->getQuit()) // Quit state conditional
            {
                this->states.top()->endState();
                delete this->states.top();
                this->states.pop();
            }
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