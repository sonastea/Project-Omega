#ifndef PLAYERGUITABS_H
#define PLAYERGUITABS_H

#include "CharacterTab.h"

enum class PlayerTabs : int { Character = 0, Inventory = 1 };

class PlayerGUITabs
{
private:
	std::vector<Tab*> tabs_;

	/* Core */
	sf::VideoMode& vm_;
	sf::Font& font_;
	Player& player_;

	sf::Clock keyTimer_;
	float keyTimeMax_;

	/* Tabs */

	/* Character Tabs */

	/* Private Initializer Functions */
	void initTabs();
	void initKeyTime();

public:
	PlayerGUITabs(sf::VideoMode&, sf::Font& font, Player& player);
	virtual ~PlayerGUITabs();

	const bool getKeyTime();
	const bool tabsOpen();

	void toggleTab(const int tab_index);

	void update();
	void render(sf::RenderTarget& target);
};

#endif // PlayerGUITabs.h