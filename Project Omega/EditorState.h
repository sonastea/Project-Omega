#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"
#include "Gui.h"
#include "PauseMenu.h"
#include "TileMap.h"

class State;
class Gui;
class PauseMenu;
class TileMap;

class EditorState :
    public State
{
private:
    // Variables
    sf::Font font;
    PauseMenu* pmenu;

    std::map<std::string, gui::Button*> buttons;

    TileMap map;

    // Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initPauseMenu();
    void initButtons();


public:
    // Constructors/Destructors
    EditorState(StateData* state_data);
    virtual ~EditorState();

    // Functions
    void updateInput(const float& dt);
    void updateButtons();
    void updatePauseMenuButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = NULL);
};

#endif

