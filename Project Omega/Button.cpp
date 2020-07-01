#include "Button.h"

Button::Button(float x, float y, float width, float height, 
	sf::Font* font, std::string text, 
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = ButtonState::IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(14);
	this->text.setStyle(sf::Text::Bold);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

}

Button::~Button()
{
}

// Accesors / Getters

const bool Button::isPressed() const
{
	return (this->buttonState == ButtonState::ACTIVE) ? true : false;
	/*if (this->buttonState == BTN_ACTIVE) { return true; }

	return false;*/
}

/*Update the booleans for hover and ACTIVE*/
void Button::update(sf::Vector2f mousePos)
{
	this->buttonState = ButtonState::IDLE;

	// Hover & ACTIVE conditional

	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = ButtonState::HOVER;

		// Button is ACTIVE
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = ButtonState::ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case ButtonState::IDLE:
		this->shape.setFillColor(this->idleColor);
		break;

	case ButtonState::HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;

	case ButtonState::ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
