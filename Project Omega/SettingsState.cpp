#include "SettingsState.h"

void SettingsState::initVariables()
{
}

void SettingsState::initBackground()
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

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Gasalt-Regular.ttf"))
	{
		throw("ERROR::SettingsState::COULD NOT LOAD FONT");
	}
}

void SettingsState::initKeybinds()
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

void SettingsState::initGui()
{
	this->buttons["BACK"] = new gui::Button
	(	
		1500.f, 880.f, 250.f, 50.f,
		&this->font, "Back", 36,
		sf::Color(100, 250, 250, 200), sf::Color(0, 250, 250, 250), sf::Color(25, 20, 20, 250),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["APPLY"] = new gui::Button
	(
		1300.f, 880.f, 250.f, 50.f,
		&this->font, "Apply", 36,
		sf::Color(100, 250, 250, 200), sf::Color(0, 250, 250, 250), sf::Color(25, 20, 20, 250),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	std::string li[] = { "2560x1440", "1920x1080", "800x600" };
	this->dropDownLists["RESOLUTIONS"] = new gui::DropDownList(800, 450, 200, 50, font, li, 3);
}


// Constructors / Destructors
SettingsState::SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
}

SettingsState::~SettingsState()
{
	auto itr = this->buttons.begin();

	for (itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
	{
		delete itr->second;
	}

	auto itr2 = this->dropDownLists.begin();

	for (itr2 = this->dropDownLists.begin(); itr2 != this->dropDownLists.end(); ++itr2)
	{
		delete itr2->second;
	}
}

// Accessors

// Functions
void SettingsState::updateInput(const float& dt)
{
}


void SettingsState::updateGui(const float& dt)
{
	/*Updates all buttons in the state and handler their functionality*/
	// Buttons
	for (auto &itr : this->buttons)
	{
		itr.second->update(this->mousePosView);
	}

	// Button functionality
	// Quit game
	if (this->buttons["BACK"]->isPressed())
	{
		this->endState();
	}

	// Apply selected settings
	if (this->buttons["APPLY"]->isPressed())
	{
		
	}

	// Dropdown lists
	for (auto &itr : this->dropDownLists)
	{
		itr.second->update(this->mousePosView, dt);
	}

	// Dropdown lists functionality
}


void SettingsState::update(const float& dt)
{
	this->updateMousePositions(); // From state class
	this->updateInput(dt);

	this->updateGui(dt);

	//system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";

}


void SettingsState::renderGui(sf::RenderTarget& target)
{
	for (auto &itr : this->buttons)
	{
		itr.second->render(target);
	}

	for (auto &itr : this->dropDownLists)
	{
		itr.second->render(target);
	}
}


void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window; // update mouse pos depending on mouse position

	target->draw(this->background);

	this->renderGui(*target);


	// REMOVE LATER !!!!! SHOWS COORDS OF MOUSE ON CURSOR 
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 25);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(20);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);
}