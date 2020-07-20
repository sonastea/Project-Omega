#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"

class State;
class PauseMenu;
class TileMap;
class sf::View;
class sf::Font;
class sf::RenderTexture;

class GameState :
    public State
{
private:
    sf::View view;
    sf::RenderTexture renderTexture;
    sf::Sprite renderSprite;

    sf::Font font;
    PauseMenu* pmenu;

    Player* player;
    sf::Texture texture;

    TileMap* tileMap;

    // Functions
    void initView();
    void initKeybinds();
    void initFonts();
    void initTextures();
    void initPauseMenu();
    void initPlayers();
    void initTileMap();

public:
    // Constructors/Destructors
    GameState(StateData* state_data);
    virtual ~GameState();

    // Functions
    void updateView(const float& dt);
    void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePauseMenuButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif