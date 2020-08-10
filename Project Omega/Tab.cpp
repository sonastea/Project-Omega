#include "stdafx.h"
#include "Tab.h"

Tab::Tab(sf::VideoMode& vm, sf::Font& font, Player& player, bool hidden)
	: vm_(vm), font_(font), player_(player), hidden_(hidden)
{
}

Tab::~Tab()
{
}

/* Accessors / Getters */
const bool& Tab::getHidden() const
{
	return this->hidden_;
}

const bool& Tab::getOpen() const
{
	return (this->hidden_ == false);
}

/* Functions */

void Tab::toggle()
{
	if (this->hidden_)
		this->hidden_ = false;
	else
		this->hidden_ = true;
}

void Tab::hide()
{
	this->hidden_ = true;
}

void Tab::show()
{
	this->hidden_ = false;
}
