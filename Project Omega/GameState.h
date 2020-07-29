#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "PlayerGUI.h"
#include "Sword.h"
#include "Bow.h"

class Player;
class PlayerGUI;
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
    sf::Vector2i viewGridPosition;
    sf::RenderTexture renderTexture;
    sf::Sprite renderSprite;

    sf::Font font;
    PauseMenu* pmenu;

    sf::Shader coreShader;

    Player* player;
    PlayerGUI* playerGUI;
    sf::Texture texture;

    TileMap* tileMap;

    // Functions
    void initDeferredRender();
    void initView();
    void initKeybinds();
    void initFonts();
    void initTextures();
    void initPauseMenu();
    void initShaders();
    void initPlayers();
    void initPlayerGUI();
    void initTileMap();

public:
    // Constructors/Destructors
    GameState(StateData* state_data);
    virtual ~GameState();

    // Functions
    void updateView(const float& dt);
    void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePlayerGUI(const float& dt);
    void updatePauseMenuButtons();
    void updateTileMap(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif