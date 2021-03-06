#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "Gui.h"

class Gui;

class PauseMenu
{
private:
	sf::Font& font; // Reference because we want to force the font 
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, gui::Button*> buttons;

	// Private Functions

public:
	// Constructors / Destructor
	PauseMenu(sf::VideoMode& vm, sf::Font& font);
	virtual ~PauseMenu();

	// Accessors
	std::map<std::string, gui::Button*>& getButtons();

	// Functions
	const bool isButtonPressed(const std::string key);
	void addButton(
		const std::string key, 
		const float width,
		const float height, 
		const float y, 
		const unsigned char_size, 
		const std::string text);
	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderTarget& target);
};

#endif