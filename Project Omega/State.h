#ifndef STATE_H
#define STATE_H

#include "Player.h"

class State
{
private:
	
protected:
	std::stack<State *>* states; // Pointer to a stack full of State* pointers
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;
	bool paused;
	float keytime;
	float keytimeMax;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;


	// Resources
	std::map<std::string, sf::Texture> textures;

	// Functions
	virtual void initKeybinds() = 0; // Each state will have to define their own keybinds


public:
	// Constructors/Destructors
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State *>* states);
	virtual ~State();

	// Accessors
	const bool& getQuit() const;
	const bool getKeytime();

	// Functions
	void endState();
	void pauseState();
	void unpauseState();

	virtual void updateMousePositions();
	virtual void updateKeytime(const float& dt);
	virtual void updateInput(const float& dt) = 0; // Pure virtual, child must define
	virtual void update(const float& dt) = 0; // Pure virtual, must be implemented
	virtual void render(sf::RenderTarget* target = NULL) = 0; // Pure virtual, must be implemented
};

#endif STATE_H