#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


// Button states
enum ButtonState {IDLE = 0, HOVER, ACTIVE};

namespace gui
{
	class Button
	{
	private:
		short unsigned buttonState;
		short unsigned id;

		// Button booleans

		bool pressed;
		bool hover;

		// Button properties

		sf::RectangleShape shape; // buttons' basic shape
		sf::Font* font;
		sf::Text text;

		// Button text colors

		sf::Color textIdleColor;
		sf::Color textHoverColor;
		sf::Color textActiveColor;

		// Button colors

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;
		
		sf::Color outlineIdleColor;
		sf::Color outlineHoverColor;
		sf::Color outlineActiveColor;


	protected:


	public:
		// Constructor/Destructor
		Button(float x, float y, float width, float height,
			sf::Font* font, std::string text, unsigned character_size,
			sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
			sf::Color idle_color, sf::Color hover_color, sf::Color active_color,
			sf::Color outline_idle_color = sf::Color::Transparent, sf::Color outline_hover_color = sf::Color::Transparent, sf::Color outline_active_color = sf::Color::Transparent,
			short unsigned id = 0);
		~Button();

		// Accessors / Getters
		const bool isPressed() const;
		const std::string getText() const;
		const short unsigned& getId() const;

		// Mutators / Setters
		void setText(const std::string text);
		void setid(const short unsigned id);

		// Functions
		void update(const sf::Vector2f& mousePos);
		void render(sf::RenderTarget& target);
	};

	class DropDownList
	{
	private:
		float keytime;
		float keytimeMax;

		sf::Font& font;
		gui::Button* activeElement;
		std::vector<gui::Button*> list;
		bool showList;

	public:
		DropDownList(float x, float y, float width, float height, 
			sf::Font& font, std::string list[], 
			unsigned nrOfElements, const unsigned default_index = 0);
		~DropDownList();

		// Accessors / Getters
		const unsigned short& getActiveElement() const;
		// Functions
		const bool getKeytime();
		void updateKeytime(const float& dt);
		void update(const sf::Vector2f& mousePos, const float& dt);
		void render(sf::RenderTarget& target);
	};
}

#endif