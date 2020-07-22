#ifndef PLAYERGUI_H
#define PLAYERGUI_H

#include "Player.h"

class Player;
class sf::RectangleShape;

class PlayerGUI
{
private:
	Player* player;

	sf::Font font;

	/* LEVEL BAR */
	std::string levelBarString;
	sf::Text levelBarText;
	sf::RectangleShape levelBarBack;

	/* EXP BAR */
	std::string expBarString;
	sf::Text expBarText;
	float expBarMaxWidth;
	sf::RectangleShape expBarBack;
	sf::RectangleShape expBarInner;

	/* HP BAR */
	std::string hpBarString;
	sf::Text hpBarText;
	float hpBarMaxWidth;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;

	/* Initialzer Functions */
	void initFont();
	void initLevelBar();
	void initEXPBar();
	void initHPBar();

public:
	/* Constructor / Destructor */
	PlayerGUI(Player* player);
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