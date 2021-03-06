#ifndef STATE_H
#define STATE_H

#include "Player.h"
#include "GraphicsSettings.h"

class Player;
class GraphicsSettings;
class State;

class StateData
{
public:
	StateData() 
	{
		this->window = nullptr;
		this->gfxSettings = nullptr;
		this->supportedKeys = nullptr;
		this->states = nullptr;
	};

	// Variables
	float gridSize;
	sf::RenderWindow* window;
	GraphicsSettings* gfxSettings;
	std::map<std::string, int>* supportedKeys;
	std::stack<State*>* states;
};

class State
{
private:
	
protected:
	StateData* stateData;
	std::stack<State *>* states; // Pointer to a stack full of State* pointers
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;
	bool paused;
	float keytime;
	float keytimeMax;
	float gridSize;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2i mousePosGrid;


	// Resources
	std::map<std::string, sf::Texture> textures;

	// Functions
	virtual void initKeybinds() = 0; // Each state will have to define their own keybinds


public:
	// Constructors/Destructors
	State(StateData* state_data);
	virtual ~State();

	// Accessors
	const bool& getQuit() const;
	const bool getKeytime();

	// Functions
	void endState();
	void pauseState();
	void unpauseState();

	virtual void updateMousePositions(sf::View* view = NULL);
	virtual void updateKeytime(const float& dt);
	virtual void updateInput(const float& dt) = 0; // Pure virtual, child must define
	virtual void update(const float& dt) = 0; // Pure virtual, must be implemented
	virtual void render(sf::RenderTarget* target = NULL) = 0; // Pure virtual, must be implemented
};

#endif