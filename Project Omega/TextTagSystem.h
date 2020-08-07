#ifndef TEXTTAGSYSTEM_H
#define TEXTTAGSYSTEM_H

enum class TagTypes : int { Default = 0, Negative = 1, Positive = 2, Experience = 3, Environmental = 4};

class TextTagSystem
{
private:
	class TextTag
	{
	private:
		sf::Text text;
		sf::Vector2f dir;
		float lifetime;
		float speed;


	public:
		/* Constructors */
		TextTag(sf::Font& font, std::string text,
			sf::Vector2f pos, sf::Vector2f dir,
			sf::Color color, unsigned char_size,
			float lifetime, float speed)
		{
			this->text.setFont(font);
			this->text.setString(text);
			this->text.setPosition(pos);
			this->text.setFillColor(color);
			this->text.setCharacterSize(char_size);

			this->dir = dir;
			this->lifetime = lifetime;
			this->speed = speed;
		}

		TextTag(TextTag* tag, sf::Vector2f pos, std::string str)
		{
			this->text = tag->text;
			this->text.setString(str);
			this->text.setPosition(pos);

			this->dir = tag->dir;
			this->lifetime = tag->lifetime;
			this->speed = tag->speed;
		}

		/* Destructors */
		~TextTag()
		{
		}
		// Accessors / Getters
		const bool isExpired() const { return this->lifetime <= 0.f; }

		/* Functions */
		void update(const float& dt)
		{
			if (this->lifetime > 0.f)
			{
				// Update lifetime of the text
				this->lifetime -= 100.f * dt;

				// Moves the text tag
				this->text.move(this->dir.x * this->speed * dt, this->dir.y * this->speed * dt);
			}
		}

		void render(sf::RenderTarget& target)
		{
			target.draw(this->text);
		}

	};

	sf::Font font_;
	std::vector<TextTag*> tags_;
	std::map<int, TextTag*> tagTemplates_;
	
	/* Private Functions */
	void initVariables();
	void initFonts(std::string font_file);
	void initTagTemplates();

public:
	TextTagSystem(std::string font_file);
	virtual ~TextTagSystem();

	/* Functions */
	void addTextTag(const unsigned tag_type, const sf::Vector2f pos, const std::string str);

	template<typename T>
	void addTextTag(const unsigned tag_type, const sf::Vector2f pos, const T value)
	{
		std::stringstream ss;
		ss << value;
		this->tags_.push_back(new TextTag(this->tagTemplates_[tag_type], pos, ss.str()));
	}

	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

#endif // TextTagSystem.h