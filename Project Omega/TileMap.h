#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

class Tile;

class TileMap
{
private:
	float gridSizeF; // F for float
	unsigned gridSizeU;
	sf::Vector2u maxSize;
	unsigned layers;
	std::vector< std::vector<std::vector<Tile>> > map;

public:
	TileMap();
	virtual ~TileMap();

	/* Functions */
	void update();
	void render(sf::RenderTarget& target);
};

#endif