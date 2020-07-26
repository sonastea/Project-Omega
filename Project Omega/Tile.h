#ifndef TILE_H
#define TILE_H

enum TileTypes {DEFAULT = 0, DAMAGING = 1, DOODAD = 2};

class Tile
{
private:

protected:
	sf::Sprite shape;
	bool collision;
	short type;

public:
	/* Constructors / Destructors */
	Tile();
	Tile(int grid_x, int grid_y, float gridSizeF, const sf::Texture& texture,
		const sf::IntRect& texture_rect,
		bool collision = false, short type = TileTypes::DEFAULT);
	virtual ~Tile();

	/* Accessors / Getters */
	const short& getType() const;
	const bool& getCollision() const;
	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	
	/* Functions */
	const bool intersects(const sf::FloatRect bounds) const;
	const std::string getAsString() const; // Returns a tile as a string

	void update();
	void render(sf::RenderTarget& target, sf::Shader* shader = NULL, const sf::Vector2f playerPosition = sf::Vector2f());
};

#endif