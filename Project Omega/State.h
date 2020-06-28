#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class State
{
private:
	std::vector<sf::Texture> textures;
public:
	// Constructors/Destructors
	State();
	virtual ~State();

	virtual void update() = 0; // Pure virtual, must be implemented
	virtual void render() = 0; // Pure virtual, must be implemented

};

#endif STATE_H