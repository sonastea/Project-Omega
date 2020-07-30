#ifndef PLAYERGUI_H
#define PLAYERGUI_H

#include "Player.h"
#include "Gui.h"

class Player;
class Gui;
class sf::RectangleShape;

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

	/* Initialzer Functions */
	void initFont();
	void initLevelBar();
	void initEXPBar();
	void initHPBar();

public:
	/* Constructor / Destructor */
	PlayerGUI(Player* player, sf::VideoMode& vm);
	virtual ~PlayerGUI();

	/* Functions */
	void updateLevelBar();
	void updateEXPBar();
	void updateHPBar();

	void update(const float& dt);

	void renderLevelBar(sf::RenderTarget& target);
	void renderEXPBar(sf::RenderTarget& target);
	void renderHPBar(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);
};

#endif