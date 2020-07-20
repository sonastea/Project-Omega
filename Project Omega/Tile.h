#ifndef TILE_H
#define TILE_H

enum TileTypes {DEFAULT = 0, DAMAGING = 1};

class Tile
{
private:

protected:
	sf::RectangleShape shape;
	bool collision;
	short type;

public:
	/* Constructors / Destructors */
	Tile();
	Tile(unsigned grid_x, unsigned grid_y, float gridSizeF, const sf::Texture& texture, 
		const sf::IntRect& texture_rect,
		bool collision = false, short type = TileTypes::DEFAULT);
	virtual ~Tile();

	/* Accessors / Getters */
	const bool& getCollision() const;
	const sf::Vector2f& getPosition() const;
	
	/* Functions */
	const std::string getAsString() const; // Returns a tile as a string

	void update();
	void render(sf::RenderTarget& target);
};

#endif