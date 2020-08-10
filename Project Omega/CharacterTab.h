#ifndef CHARACTERTAB_H
#define CHARACTERTAB_H

#include "Tab.h"

class CharacterTab :
    public Tab
{
private:
	sf::RectangleShape back_;
	sf::Text infoText_;

	/* Initializer Functions */
	void initText();

public:
	/* Constructor / Destructor */
	CharacterTab(sf::VideoMode& vm, sf::Font& font, Player& player);
	~CharacterTab();

	/* Functions */
	void update();
	void render(sf::RenderTarget& target);
};

#endif // CharacterTab.h