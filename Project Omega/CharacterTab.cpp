#include "stdafx.h"
#include "CharacterTab.h"

void CharacterTab::initText()
{
	//Text
	this->infoText_.setFont(this->font_);
	this->infoText_.setCharacterSize(gui::calcCharSize(this->vm_, 100));
	this->infoText_.setFillColor(sf::Color(200, 200, 200, 240));
	this->infoText_.setPosition(this->back_.getPosition().x + 20.f, this->back_.getPosition().y + 20.f);

	this->infoText_.setString(this->player_.toStringCharacterTab());
}

/* Constructor / Destructor */
CharacterTab::CharacterTab(sf::VideoMode& vm, sf::Font& font, Player& player)
	: Tab(vm, font, player, true)
{
	/* Background */
	this->back_.setFillColor(sf::Color(520, 20, 20, 240));
	this->back_.setSize(sf::Vector2f(gui::p2pX(45.f, this->vm_), static_cast<float>(this->vm_.height)));

	this->initText();
}

CharacterTab::~CharacterTab()
{
}

void CharacterTab::update()
{
	if (!this->hidden_)
	{
		// Update character info
		this->infoText_.setString(this->player_.toStringCharacterTab());
	}
}

void CharacterTab::render(sf::RenderTarget& target)
{
	if (!this->hidden_)
	{
		target.draw(back_);
		target.draw(infoText_);
	}
}
