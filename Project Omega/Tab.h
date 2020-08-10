#ifndef TAB_H
#define TAB_H

#include "Player.h"
#include "Gui.h"

class Tab
{
protected:
	sf::VideoMode& vm_;
	sf::Font& font_;
	Player& player_;
	bool hidden_;

public:
	Tab(sf::VideoMode& vm, sf::Font& font, Player& player, bool hidden);
	virtual ~Tab();

	/* Accessors / Getters */
	const bool& getHidden() const;
	const bool& getOpen() const;
	void toggle();

	/* Functions */
	void hide();
	void show();

	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

#endif // Tab.h