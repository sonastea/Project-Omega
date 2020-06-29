#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	: State()
{
}

GameState::~GameState()
{
}

void GameState::endState()
{
}

void GameState::update(const float& dt)
{
	std::cout << "Hello from gamestate!" << "\n";
}

void GameState::render(sf::RenderTarget* target)
{
}
