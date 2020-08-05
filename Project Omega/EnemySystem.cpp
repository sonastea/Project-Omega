#include "stdafx.h"
#include "EnemySystem.h"

/* Constructor */
EnemySystem::EnemySystem(std::vector<Enemy*>& activeEnemies, 
	std::map<std::string, sf::Texture>& textures):
	textures(textures), activeEnemies(activeEnemies)
{
}

/* Destructor */
EnemySystem::~EnemySystem()
{
}

/* Functions */
void EnemySystem::createEnemy(short type, const sf::Vector2f pos)
{
	switch (type)
	{
		case to_int(EnemyTypes::Rat):
			this->activeEnemies.push_back(new Rat(pos, this->textures["RAT1_SHEET"]));
			break;
		default:
			std::cout << "ERROR::ENEMYSYSTEM::CREATEENEMY::TYPE DOES NOT EXIST!" << "\n";
			break;
	}
}

void EnemySystem::update(const float& dt)
{
}

void EnemySystem::render(sf::RenderTarget* target)
{
}
