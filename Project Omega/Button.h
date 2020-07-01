#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


// Button states
enum ButtonState{IDLE = 0, HOVER, ACTIVE};


class Button 
{
private:
	short unsigned buttonState;

	// Button booleans

	bool pressed;
	bool hover;

	// Button properties

	sf::RectangleShape shape; // buttons' basic shape
	sf::Font* font;
	sf::Text text;

	// Button colors

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;


protected:


public:
	// Constructor/Destructor
	Button(float x, float y, float width, float height, 
		sf::Font* font, std::string text, 
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	// Accessors / Getters
	const bool isPressed() const;

	// Functions
	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

#endif