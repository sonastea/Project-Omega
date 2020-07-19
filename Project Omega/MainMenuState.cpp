#include "stdafx.h"
#include "MainMenuState.h"


// Initializer Functions

void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	this->background.setSize
	(sf::Vector2f
	(
		static_cast<float>(this->window->getSize().x),
   		static_cast<float>(this->window->getSize().y)
	)
	);

	if (!this->bgTexture.loadFromFile("Assets/Images/Backgrounds/bg-1-1080p.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->bgTexture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Gasalt-Regular.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds()
{

	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new gui::Button
	(	200.f, 300.f, 150.f, 50.f,
		&this->font, "New Game", 36,
		sf::Color(100, 250, 250, 200), sf::Color(0, 250, 250, 250), sf::Color(25, 20, 20, 250),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["SETTINGS_STATE"] = new gui::Button
	(	200.f, 400.f, 150.f, 50.f,
		&this->font, "Settings", 36,
		sf::Color(100, 250, 250, 200), sf::Color(0, 250, 250, 250), sf::Color(25, 20, 20, 250),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["EDITOR_STATE"] = new gui::Button
	(	200.f, 500.f, 150.f, 50.f,
		&this->font, "Editor", 36,
		sf::Color(100, 250, 250, 200), sf::Color(0, 250, 250, 250), sf::Color(25, 20, 20, 250),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["EXIT_STATE"] = new gui::Button
	(	200.f, 600.f, 150.f, 50.f,
		&this->font, "Quit", 36,
		sf::Color(100, 250, 250, 200), sf::Color(0, 250, 250, 250), sf::Color(25, 20, 20, 250),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);
}


// Constructor
MainMenuState::MainMenuState(StateData* state_data)
	: State(state_data)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

// Destructor
MainMenuState::~MainMenuState()
{
	auto itr = this->buttons.begin();

	for (itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
	{
		delete itr->second;
	}
}

// Functions
void MainMenuState::updateInput(const float& dt)
{
}

void MainMenuState::updateButtons()
{
	/*Updates all buttons in the state and handler their functionality*/
	for (auto &itr : this->buttons)
	{
		itr.second->update(this->mousePosView);
	}

	// New game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->stateData));
	}

	// Settings
	if (this->buttons["SETTINGS_STATE"]->isPressed())
	{
		this->states->push(new SettingsState(this->stateData));
	}

	// Editor
	if (this->buttons["EDITOR_STATE"]->isPressed())
	{
		this->states->push(new EditorState(this->stateData));
	}

	// Quit game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions(); // From state class
	this->updateInput(dt);

	this->updateButtons();

	//system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";

}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
	for (auto &itr : this->buttons)
	{
		itr.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window; // update mouse pos depending on mouse position

	target->draw(this->background);

	this->renderButtons(*target);


	// REMOVE LATER !!!!! SHOWS COORDS OF MOUSE ON CURSOR 
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 25);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(20);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);*/
}