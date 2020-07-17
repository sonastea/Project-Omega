#ifndef TILE_H
#define TILE_H

class Tile
{
private:

protected:
	sf::RectangleShape shape;

public:
	// Constructors / Destructors
	Tile();
	Tile(float x, float y, float gridSizeF); // F for float
	virtual ~Tile();

	/* Functions */
	void update();
	void render(sf::RenderTarget& target);
};

#endif