#ifndef ENTITY_H
#define ENTITY_H


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>


#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"


class Entity
{
private:
	void initVariables();
protected:
	sf::Texture* texture; //Point to a texture in the state where you loaded the texture, without having to load it every creation
	sf::Sprite* sprite;

	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	// Components functions
	void createSprite(sf::Texture* texture);

	// Functions
	virtual void move(const float& dt, const sf::Vector2f& direction);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

#endif