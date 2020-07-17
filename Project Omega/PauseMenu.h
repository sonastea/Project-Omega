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
	PauseMenu(sf::RenderWindow& window, sf::Font& font);
	virtual ~PauseMenu();

	// Accessors
	std::map<std::string, gui::Button*>& getButtons();

	// Functions
	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key, float y, const std::string text);
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);
};

#endif