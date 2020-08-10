#ifndef PLAYERGUI_H
#define PLAYERGUI_H

#include "PlayerGUITabs.h"

class PlayerGUI
{
private:
	Player* player;

	sf::VideoMode& vm;
	sf::Font font;

	/* LEVEL BAR */
	std::string levelBarString;
	sf::Text levelBarText;
	sf::RectangleShape levelBarBack;

	/* EXP BAR */
	gui::ProgressBar* expBar;

	/* HP BAR */
	gui::ProgressBar* hpBar;

	/* Player GUI Tabs */
	PlayerGUITabs* playerTabs_;

	/* Initialzer Functions */
	void initFont();
	void initLevelBar();
	void initEXPBar();
	void initHPBar();
	void initPlayerTabs(sf::VideoMode& vm, sf::Font& font, Player& player);

public:
	/* Constructor / Destructor */
	PlayerGUI(Player* player, sf::VideoMode& vm);
	virtual ~PlayerGUI();

	/* Accessors / Getters */
	const bool getTabsOpen() const;
	void toggleCharacterTab();

	/* Functions */
	void updateLevelBar();
	void updateEXPBar();
	void updateHPBar();
	void updatePlayerTabs();

	void update(const float& dt);

	void renderLevelBar(sf::RenderTarget& target);
	void renderEXPBar(sf::RenderTarget& target);
	void renderHPBar(sf::RenderTarget& target);
	void renderPlayerTabs(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);
};

#endif