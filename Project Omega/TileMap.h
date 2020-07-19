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
	std::vector< std::vector< std::vector<Tile* > > > map;
	std::string textureFile;
	sf::Texture tileSheet;

public:
	/* Constructors / Destructor */
	TileMap(float gridSize, unsigned width, unsigned height, std::string texture_file);
	virtual ~TileMap();

	/* Accessors / Getters */
	const sf::Texture* getTileSheet() const;

	/* Functions */
	void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);

	void saveToFile(const std::string file_name);
	void loadFromFile(const std::string file_name);

	void update();
	void render(sf::RenderTarget& target);
};

#endif