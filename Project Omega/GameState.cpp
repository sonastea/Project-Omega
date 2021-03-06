#include "stdafx.h"
#include "GameState.h"

// Initializer functions
void GameState::initDeferredRender()
{
	this->renderTexture.create(
		this->stateData->gfxSettings->resolution.width,
		this->stateData->gfxSettings->resolution.height
	);

	this->renderSprite.setTexture(this->renderTexture.getTexture());
	this->renderSprite.setTextureRect(
		sf::IntRect(
			0, 
			0, 
			this->stateData->gfxSettings->resolution.width, 
			this->stateData->gfxSettings->resolution.height
		)
	);
}

void GameState::initView()
{
	this->view.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width / 2),
			static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)
		)
	);

	this->view.setCenter(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f,
			static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f
		)
	);
}

void GameState::initKeybinds()
{

	std::ifstream ifs("Config/gamestate_keybinds.ini");

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

void GameState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Gasalt-Regular.ttf"))
	{
		throw("ERROR::GAMESTATE::COULD NOT LOAD FONT");
	}
}

void GameState::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Assets/Models/Player/player-sheet-video-2.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}

	if (!this->textures["RAT1_SHEET"].loadFromFile("Assets/Models/Enemy/slime2-1_64x64.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_RAT1_TEXTURE";
	}
}

void GameState::initPauseMenu()
{
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);

	this->pmenu->addButton("QUIT", gui::p2pY(74.1f, vm), gui::p2pX(13.f, vm), gui::p2pY(4.6f, vm), gui::calcCharSize(vm), "Quit");
}

void GameState::initShaders()
{
	if (!this->coreShader.loadFromFile("vertex_shader.vert", "fragment_shader.frag"))
	{
		std::cout << "ERROR::GAMESTATE::COULD NOT LOAD SHADER." << "\n";
	}
}

void GameState::initKeyTime()
{
	this->keyTimeMax_ = 0.3f;
	this->keyTimer_.restart();
}

void GameState::initDebugText()
{
	this->debugText_.setFont(this->font);
	this->debugText_.setFillColor(sf::Color::White);
	this->debugText_.setCharacterSize(16);
	this->debugText_.setPosition(15.f, this->window->getSize().y / 2.f);
}

void GameState::initPlayers()
{
	this->player = new Player(sf::Vector2f(220, 220), this->textures["PLAYER_SHEET"]);
}

void GameState::initPlayerGUI()
{
	this->playerGUI = new PlayerGUI(this->player, this->stateData->gfxSettings->resolution);
}

void GameState::initEnemySystem()
{
	this->enemySystem = new EnemySystem(this->activeEnemies, this->textures, *this->player);
}

void GameState::initTileMap()
{
	this->tileMap = new TileMap("text.slmp");
}

void GameState::initSystems()
{
	this->text_tag_system_ = new TextTagSystem("Fonts/EightBitDragon-anqx.ttf");
}

// Constructors / Destructors
GameState::GameState(StateData* state_data)
	: State(state_data)
{
	this->initDeferredRender();
	this->initView();
	this->initKeybinds();
	this->initFonts();
	this->initTextures();
	this->initPauseMenu();
	this->initShaders();
	this->initKeyTime();

	this->initPlayers();
	this->initPlayerGUI();
	this->initEnemySystem();
	this->initTileMap();
	this->initSystems();
}

GameState::~GameState()
{
	delete this->pmenu;
	delete this->player;
	delete this->playerGUI;
	delete this->enemySystem;
	delete this->tileMap;
	delete this->text_tag_system_;

	for (size_t i = 0; i < this->activeEnemies.size(); i++)
	{
		delete this->activeEnemies[i];
	}
}

// Accessors / Getters
const bool GameState::getKeyTime()
{
	if (this->keyTimer_.getElapsedTime().asSeconds() >= this->keyTimeMax_)
	{
		this->keyTimer_.restart();
		return true;
	}
	return false;
}

/* Functions */
void GameState::updateView(const float& dt)
{
	this->view.setCenter(
		std::floor(this->player->getPosition().x + (static_cast<float>(this->mousePosWindow.x) - static_cast<float>(this->stateData->gfxSettings->resolution.width / 2)) / 10.f),
		std::floor(this->player->getPosition().y + (static_cast<float>(this->mousePosWindow.y) - static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)) / 10.f)
	);

	
	//std::cout << this->tileMap->getMaxSizeF().x << " " << this->view.getSize().x << "\n";

	if (this->tileMap->getMaxSizeF().x >= this->view.getSize().x)
	{
		if (this->view.getCenter().x - this->view.getSize().x / 2.f < 0.f)
		{
			this->view.setCenter(0.f + this->view.getSize().x / 2.f, this->view.getCenter().y);
		}
		else if (this->view.getCenter().x + this->view.getSize().x / 2.f > this->tileMap->getMaxSizeF().x)
		{
			this->view.setCenter(this->tileMap->getMaxSizeF().x - this->view.getSize().x / 2.f, this->view.getCenter().y);
		}
	}

	if (this->tileMap->getMaxSizeF().y >= this->view.getSize().y)
	{
		if (this->view.getCenter().y - this->view.getSize().y / 2.f < 0.f)
		{
			this->view.setCenter(this->view.getCenter().x, 0.f + this->view.getSize().y / 2.f);
		}
		else if (this->view.getCenter().y + this->view.getSize().y / 2.f > this->tileMap->getMaxSizeF().y)
		{
			this->view.setCenter(this->view.getCenter().x, this->tileMap->getMaxSizeF().y - this->view.getSize().y / 2.f);
		}
	}

	this->viewGridPosition.x = static_cast<int>(this->view.getCenter().x) / static_cast<int>(this->stateData->gridSize);
	this->viewGridPosition.y = static_cast<int>(this->view.getCenter().y) / static_cast<int>(this->stateData->gridSize);
}

void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime())
	{
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}
}

void GameState::updatePlayerInput(const float& dt)
{
	// Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(sf::Vector2f(-1.f, 0.f), dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(sf::Vector2f(1.f, 0.f), dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
	{
		this->player->move(sf::Vector2f(0.f, -1.f), dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
	{
		this->player->move(sf::Vector2f(0.f, 1.f), dt);
	}
}

void GameState::updatePlayerGUI(const float& dt)
{
	this->playerGUI->update(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("TOGGLE_PLAYER_CHARACTER_TAB"))) && this->getKeytime())
	{
		this->playerGUI->toggleCharacterTab();
	}
}

void GameState::updatePauseMenuButtons()
{
	if (this->pmenu->isButtonPressed("QUIT"))
		this->endState();
}

void GameState::updateTileMap(const float& dt)
{
	this->tileMap->updateWorldBoundsCollision(this->player, dt);
	this->tileMap->updateTileCollision(this->player, dt);
	this->tileMap->updateTiles(this->player, dt, *this->enemySystem);
}

void GameState::updatePlayer(const float& dt)
{
	this->player->update(dt, this->mousePosView, this->view);
}

void GameState::updateCombatAndEnemies(const float& dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->getWeapon()->getAttackTimer())
		this->player->setInitAttack(true);

	unsigned index = 0;

	for (auto* enemy : this->activeEnemies)
	{
		enemy->update(dt, this->mousePosView, this->view);

		this->tileMap->updateWorldBoundsCollision(enemy, dt);
		this->tileMap->updateTileCollision(enemy, dt);

	this->updateCombat(enemy, index, dt);

		// Sketchy
		if (enemy->isDead())
		{
			this->player->gainEXP(enemy->getGainExp());
			this->text_tag_system_->addTextTag(to_int(TagTypes::Experience), sf::Vector2f(this->player->getPosition().x - 40.f, this->player->getPosition().y - 30.f), static_cast<int>(enemy->getGainExp()), "+", "EXP");
			
			this->enemySystem->removeEnemy(index);
			continue;
		}
		else if (enemy->getDespawnTimerDone())
		{
			this->enemySystem->removeEnemy(index);
			continue;
		}
		++index;
	}
	this->player->setInitAttack(false);
}

void GameState::updateCombat(Enemy* enemy, const int index, const float& dt)
{
	if (this->player->getInitAttack()
		&& enemy->getGlobalBounds().contains(this->mousePosView) 
		&& enemy->getSpriteDistance(*this->player) < this->player->getWeapon()->getRange()
		&& enemy->getDamageTimerDone())	
	{
		//Get to this!!!!
		int dmg = static_cast<int>(this->player->getDamage());
		enemy->loseHP(dmg);
		enemy->resetDamageTimer();
		this->text_tag_system_->addTextTag(to_int(TagTypes::Default), enemy->getPosition(), dmg, "", "");
		std::cout << "Hit" << "\n";
	}

	// Check for enemy damage
	if (enemy->getGlobalBounds().intersects(this->player->getGlobalBounds()) && this->player->getDamageTimer())
	{
		int dmg = enemy->getAttributeComponent()->damageMax;
		this->player->loseHP(dmg);
		this->text_tag_system_->addTextTag(to_int(TagTypes::Negative), sf::Vector2f(player->getPosition().x - 30.f, player->getPosition().y), dmg, "-", "HP");
		std::cout << "Enemy Hit" << "\n";
	}
}

void GameState::updateDebugText(const float& dt)
{
	std::stringstream ss;

	ss << "Mouse Pos View: " << this->mousePosView.x << " " << this->mousePosView.y << "\n"
		<< "Active Enemies: " << this->activeEnemies.size() << "\n";

	this->debugText_.setString(ss.str());
}

void GameState::update(const float& dt)
{
	this->updateMousePositions(&this->view);
	this->updateKeytime(dt);
	this->updateInput(dt);

	this->updateDebugText(dt);

	if (!this->paused) // Unpaused update
	{
		this->updateView(dt);

		this->updatePlayerInput(dt); // Wait for input

		this->updateTileMap(dt); // Check for the collision

		this->updatePlayer(dt);

		this->updatePlayerGUI(dt);

		// Update all enemies
		// CHANGE: Loop outside, and make functions take one enemy at a time
		this->updateCombatAndEnemies(dt);

		// Update systems
		this->text_tag_system_->update(dt);
	}
	else // Paused update
	{
		this->pmenu->update(this->mousePosWindow);
		this->updatePauseMenuButtons();
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->renderTexture.clear();

	this->renderTexture.setView(this->view);

	this->tileMap->render(
		this->renderTexture, 
		this->viewGridPosition, 
		&this->coreShader,
		this->player->getCenter(),
		false
	);

	// Enemy rendering
	for (auto* enemy : this->activeEnemies)
	{
		enemy->render(this->renderTexture, &this->coreShader, this->player->getCenter(), true);
	}

	this->player->render(this->renderTexture, &this->coreShader, this->player->getCenter(), true);

	this->tileMap->renderDeferred(this->renderTexture, &this->coreShader, this->player->getCenter());

	this->text_tag_system_->render(this->renderTexture);

	// Render GUI
	this->renderTexture.setView(this->renderTexture.getDefaultView());
	this->playerGUI->render(this->renderTexture);

	if (this->paused) // Paused menu render
	{
		//this->renderTexture.setView(this->renderTexture.getDefaultView());
		this->pmenu->render(this->renderTexture);
	}

	// Debug Text
	this->renderTexture.draw(debugText_);

	// FINAL RENDER
	this->renderTexture.display();
	//this->renderSprite.setTexture(this->renderTexture.getTexture());
	target->draw(this->renderSprite);
}