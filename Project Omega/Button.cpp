#include "Button.h"

Button::Button(float x, float y, float width, float height, 
	sf::Font* font, std::string text, unsigned character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idle_color, sf::Color hover_color, sf::Color active_color)
{
	this->buttonState = ButtonState::IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idle_color);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(text_idle_color);
	this->text.setCharacterSize(character_size);
	this->text.setStyle(sf::Text::Bold);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->textIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;

	this->idleColor = idle_color;
	this->hoverColor = hover_color;
	this->activeColor = active_color;

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
	case IDLE:
		this->shape.setFillColor(this->idleColor);
		this->text.setFillColor(this->textIdleColor);
		break;

	case HOVER:
		this->shape.setFillColor(this->hoverColor);
		this->text.setFillColor(this->textHoverColor);
		break;

	case ACTIVE:
		this->shape.setFillColor(this->activeColor);
		this->text.setFillColor(this->textActiveColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Blue);
		break;
	}
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}
