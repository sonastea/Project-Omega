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
void EnemySystem::createEnemy(const short type, const sf::Vector2f pos, EnemySpawnerTile& enemy_spawner_tile)
{
	switch (type)
	{
		case to_int(EnemyTypes::Rat):
			this->activeEnemies.push_back(new Rat(pos, this->textures["RAT1_SHEET"], enemy_spawner_tile));
			enemy_spawner_tile.increaseEnemyCounter();
			break;
		default:
			std::cout << "ERROR::ENEMYSYSTEM::CREATEENEMY::TYPE DOES NOT EXIST!" << "\n";
			break;
	}
}

void EnemySystem::removeEnemy(const int index)
{
	this->activeEnemies[index]->getEnemySpawnerTile().decreaseEnemyCounter();
	delete this->activeEnemies[index];
	this->activeEnemies.erase(this->activeEnemies.begin() + index);
}

void EnemySystem::update(const float& dt)
{
}

void EnemySystem::render(sf::RenderTarget* target)
{
}
