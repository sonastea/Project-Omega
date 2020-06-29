#ifndef STATE_H
#define STATE_H


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>


#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"


class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;

public:
	// Constructors/Destructors
	State(sf::RenderWindow* window);
	State();
	virtual ~State();

	virtual void endState() = 0;

	virtual void update(const float& dt) = 0; // Pure virtual, must be implemented
	virtual void render(sf::RenderTarget* target = nullptr) = 0; // Pure virtual, must be implemented

};

#endif STATE_H