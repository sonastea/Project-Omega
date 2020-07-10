#include "EditorState.h"

// Initializer Functions

void EditorState::initVariables()
{
}

void EditorState::initBackground()
{
}

void EditorState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Gasalt-Regular.ttf"))
	{
		throw("ERROR::EditorState::COULD NOT LOAD FONT");
	}
}

void EditorState::initKeybinds()
{

	std::ifstream ifs("Config/editorstate_keybinds.ini");

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

void EditorState::initButtons()
{
}


// Constructor
EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

// Destructor
EditorState::~EditorState()
{
	auto itr = this->buttons.begin();

	for (itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
	{
		delete itr->second;
	}
}

// Functions
void EditorState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}


void EditorState::updateButtons()
{
	/*Updates all buttons in the state and handler their functionality*/
	for (auto& itr : this->buttons)
	{
		itr.second->update(this->mousePosView);
	}
}

void EditorState::update(const float& dt)
{
	this->updateMousePositions(); // From state class
	this->updateInput(dt);

	this->updateButtons();

	//system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";

}

void EditorState::renderButtons(sf::RenderTarget& target)
{
	for (auto& itr : this->buttons)
	{
		itr.second->render(target);
	}
}

void EditorState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window; // update mouse pos depending on mouse position

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
