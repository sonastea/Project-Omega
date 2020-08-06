#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include "Rat.h"

enum class EnemyTypes : int { Rat = 0};

class EnemySystem
{
private:
	std::map<std::string, sf::Texture>& textures;
	std::vector<Enemy*>& activeEnemies;

public:
	EnemySystem(std::vector<Enemy*>& activeEnemies, 
				std::map<std::string, sf::Texture>& textures);
	virtual ~EnemySystem();

	// Accessors / Getters

	// Modifiers

	/* Functions */
	void createEnemy(short type, const sf::Vector2f pos);

	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

#endif // EnemeySystem.h