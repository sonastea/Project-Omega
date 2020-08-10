#include "stdafx.h"
#include "PlayerGUITabs.h"

/* Private Initializer Functions */
void PlayerGUITabs::initTabs()
{
	this->tabs_.push_back(new CharacterTab(vm_, font_, player_));
}

void PlayerGUITabs::initKeyTime()
{
	this->keyTimeMax_ = 0.3f;
	this->keyTimer_.restart();
}

PlayerGUITabs::PlayerGUITabs(sf::VideoMode& vm, sf::Font& font, Player& player)
	: vm_(vm), font_(font), player_(player)
{
	this->initTabs();
	this->initKeyTime();
}

PlayerGUITabs::~PlayerGUITabs()
{
}

const bool PlayerGUITabs::getKeyTime()
{
	if (this->keyTimer_.getElapsedTime().asSeconds() >= this->keyTimeMax_)
	{
		this->keyTimer_.restart();
		return true;
	}
	return false;
}

const bool PlayerGUITabs::tabsOpen()
{
	// Loop through tabs and check if they are open
	bool open = false;
	for (size_t i = 0; i < this->tabs_.size() && !open; i++)
	{
		if (this->tabs_[i]->getOpen())
			open = true;
	}
	return open;
}

void PlayerGUITabs::toggleTab(const int tab_index)
{
	if (tab_index >= 0 || tab_index < this->tabs_.size())
		this->tabs_[tab_index]->toggle();
}

void PlayerGUITabs::update()
{
	for (size_t i = 0; i < this->tabs_.size(); i++)
	{
		if (this->tabs_[i]->getOpen())
			this->tabs_[i]->update();
	}
}

void PlayerGUITabs::render(sf::RenderTarget& target)
{
	for (size_t i = 0; i < this->tabs_.size(); i++)
	{
		if (this->tabs_[i]->getOpen())
			this->tabs_[i]->render(target);
	}
}