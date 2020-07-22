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

	/* EXP BAR */

	/* HP BAR */
	std::string hpBarString;
	sf::Text hpBarText;
	float hpBarMaxWidth;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;

	/* Initialzer Functions */
	void initFont();
	void initHPBar();

public:
	/* Constructor / Destructor */
	PlayerGUI(Player* player);
	virtual ~PlayerGUI();

	/* Functions */
	void updateHPBar();
	void update(const float& dt);

	void renderHPBar(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

#endif