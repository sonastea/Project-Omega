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
	this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50,
		&this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)); // delete in memory

	this->buttons["SETTINGS"] = new Button(100, 200, 150, 50,
		&this->font, "Settings",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50,
		&this->font, "Quit",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}


// Constructor
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State *>* states)
	: State(window, supportedKeys, states)
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
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
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

void MainMenuState::renderButtons(sf::RenderTarget* target)
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

	this->renderButtons(target);


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
