#include "stdafx.h"
#include "TextTagSystem.h"

/* Private Functions */
void TextTagSystem::initVariables()
{
}

void TextTagSystem::initFonts(std::string font_file)
{
	if (!this->font_.loadFromFile(font_file))
	{
		std::cout << "ERROR:TEXTTAGSYSTEM::CONSTRUCTOR::FAILED TO LOAD FONT: " << font_file << "\n";
	}
}

void TextTagSystem::initTagTemplates()
{
	this->tagTemplates_[to_int(TagTypes::Default)] = new TextTag(font_, "", sf::Vector2f(100.f, 100.f), sf::Vector2f(0.f, -1.f), sf::Color::White, 30, 100.f, 100.f, 300.f, 2);
	this->tagTemplates_[to_int(TagTypes::Negative)] = new TextTag(font_, "", sf::Vector2f(100.f, 100.f), sf::Vector2f(0.f, 1.f), sf::Color::Red, 30, 100.f, 100.f, 300.f, 2);
	this->tagTemplates_[to_int(TagTypes::Experience)] = new TextTag(font_, "", sf::Vector2f(100.f, 100.f), sf::Vector2f(0.f, -1.f), sf::Color::Green, 45, 150.f, 150.f, 300.f, 2);
}

/* Constructor  / Destructors */
TextTagSystem::TextTagSystem(std::string font_file)
{
	this->initVariables();
	this->initFonts(font_file);
	this->initTagTemplates();
}

TextTagSystem::~TextTagSystem()
{
	// Clean uo tags
	for (auto* tag : this->tags_)
	{
		delete tag;
	}
	
	// Clean up templates
	for (auto& tag : this->tagTemplates_)
	{
		delete tag.second;
	}
}

/* Functions */
void TextTagSystem::addTextTag(const unsigned tag_type, const sf::Vector2f pos, const std::string str,
	const std::string prefix, const std::string postfix)
{
	std::stringstream ss;
	ss << prefix << " " << str << " " << postfix;
	this->tags_.push_back(new TextTag(this->tagTemplates_[tag_type], pos, str));
}

void TextTagSystem::update(const float& dt)
{
	for (size_t i = 0; i < this->tags_.size(); i++)
	{
		this->tags_[i]->update(dt);

		if (this->tags_[i]->isExpired())
		{
			delete this->tags_[i];
			this->tags_.erase(this->tags_.begin() + i);
		}
	}
}

void TextTagSystem::render(sf::RenderTarget& target)
{
	for (auto& tag : this->tags_)
	{
		tag->render(target);
	}
}

