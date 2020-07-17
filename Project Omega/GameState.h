#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"

class State;
class PauseMenu;
class TileMap;

class GameState :
    public State
{
private:
    sf::Font font;
    PauseMenu* pmenu;

    Player* player;
    sf::Texture texture;

    TileMap map;

    // Functions
    void initKeybinds();
    void initFonts();
    void initTextures();
    void initPauseMenu();
    void initPlayers();

public:
    // Constructors/Destructors
    GameState(StateData* state_data);
    virtual ~GameState();

    // Functions
    void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePauseMenuButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif