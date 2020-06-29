#ifndef GAME_H
#define GAME_H


#include "GameState.h"


class Game
{
private:
	// Variables
	sf::RenderWindow* window; // Pointer 
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt; // Delta Time

	std::stack<State *> states; // Pointer

	// Initialization
	void initWindow();
	void initStates();

public:
	// Constructors/Destructors
	Game();
	virtual ~Game();

	// Functions
	void updateDt(); // Update delta time
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif