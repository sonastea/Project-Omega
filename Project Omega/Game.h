#ifndef GAME_H
#define GAME_H


#include "MainMenuState.h"

class Game
{
private:
	// Variables
	sf::RenderWindow* window; // Pointer 
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt; // Delta Time

	std::stack<State *> states; // Pointer

	std::map<std::string, int> supportedKeys; // Keybinds for the game

	// Initialization
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();

public:
	// Constructors/Destructors
	Game();
	virtual ~Game();

	// Functions

	// Regular
	void endApplication();

	// Update
	void updateDt(); // Update delta time
	void updateSFMLEvents();
	void update();

	// Render
	void render();

	// Core
	void run();
};

#endif