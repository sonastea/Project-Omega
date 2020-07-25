#include "stdafx.h"
#include "SettingsState.h"

/* Initializer Functions */

void SettingsState::initVariables()
{
	this->modes = sf::VideoMode::getFullscreenModes();
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
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

	// Initialize background
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)
		)
	);

	if (!this->bgTexture.loadFromFile("Assets/Textures/Background/bg-1-1080p.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->bgTexture);

	// Buttons
	this->buttons["BACK"] = new gui::Button
	(	
		gui::p2pX(78.1f, vm), gui::p2pY(81.5f, vm), 
		gui::p2pX(13.f, vm), gui::p2pY(4.6f, vm),
		&this->font, "Back", gui::calcCharSize(vm),
		sf::Color(100, 250, 250, 200), sf::Color(0, 250, 250, 250), sf::Color(25, 20, 20, 250),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["APPLY"] = new gui::Button
	(
		gui::p2pX(67.7f, vm), gui::p2pY(81.5f, vm), 
		gui::p2pX(13.f, vm), gui::p2pY(4.6f, vm),
		&this->font, "Apply", gui::calcCharSize(vm),
		sf::Color(100, 250, 250, 200), sf::Color(0, 250, 250, 250), sf::Color(25, 20, 20, 250),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	// Modes
	std::vector<std::string> modes_str;
	for (auto& i : this->modes)
	{
		modes_str.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));
	}

	// Drop down lists 
	this->dropDownLists["RESOLUTIONS"] = new gui::DropDownList(
		gui::p2pX(42.f, vm), gui::p2pY(42.f, vm), 
		gui::p2pX(10.4f, vm), gui::p2pY(4.6f, vm), 
		font, modes_str.data(), modes_str.size());

	// Init text
	this->optionsText.setFont(this->font);
	this->optionsText.setPosition(sf::Vector2f(gui::p2pX(5.2f, vm), gui::p2pY(41.7f, vm)));
	this->optionsText.setCharacterSize(gui::calcCharSize(vm, 70));
	this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));


	this->optionsText.setString(
		"Resolution \n\nFullscreen \n\nVsync \n\nAntialiasing \n\n"
	);
}

void SettingsState::resetGui()
{
	/*
	* Clears the GUI elements and re-initializes the GUI.
	* 
	* @return void
	*/

	for (auto itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
	{
		delete itr->second;
	}
	this->buttons.clear();


	for (auto itr2 = this->dropDownLists.begin(); itr2 != this->dropDownLists.end(); ++itr2)
	{
		delete itr2->second;
	}
	this->dropDownLists.clear();

	this->initGui();
}

// Constructors / Destructors
SettingsState::SettingsState(StateData* state_data)
	: State(state_data)
{
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
	this->resetGui();
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
		itr.second->update(this->mousePosWindow);
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
		// TEST REMOVE LATER
		this->stateData->gfxSettings->resolution = this->modes[this->dropDownLists["RESOLUTIONS"]->getActiveElementId()];
		this->window->create(this->stateData->gfxSettings->resolution, this->stateData->gfxSettings->title, sf::Style::Default);
		this->resetGui();
	}

	// Dropdown lists
	for (auto &itr : this->dropDownLists)
	{
		itr.second->update(this->mousePosWindow, dt);
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

	target->draw(this->optionsText);

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