#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "PlayerGUI.h"
#include "Sword.h"
#include "Bow.h"
#include "TextTagSystem.h"

class TextTagSystem;

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

    sf::Clock keyTimer_;
    float keyTimeMax_;

    Player* player;
    PlayerGUI* playerGUI;
    sf::Texture texture;

    TileMap* tileMap;

    std::vector<Enemy*> activeEnemies;
    EnemySystem* enemySystem;

    // Systems
    TextTagSystem* text_tag_system_;

    // Functions
    void initDeferredRender();
    void initView();
    void initKeybinds();
    void initFonts();
    void initTextures();
    void initPauseMenu();
    void initShaders();
    void initKeyTime();
    void initPlayers();
    void initPlayerGUI();
    void initEnemySystem();
    void initTileMap();
    void initSystems();

public:
    // Constructors/Destructors
    GameState(StateData* state_data);
    virtual ~GameState();
    
    // Accessors / Getters
    const bool geKeyTime();

    // Functions
    void updateView(const float& dt);
    void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePlayerGUI(const float& dt);
    void updatePauseMenuButtons();
    void updateTileMap(const float& dt);
    void updatePlayer(const float& dt);
    void updateCombatAndEnemies(const float& dt);
    void updateCombat(Enemy* enemy, const int index, const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif