#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt; // Delta Time

	// Initialization
	void initWindow();

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