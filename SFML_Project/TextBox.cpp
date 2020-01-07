#include "TextBox.h"

TextBox::TextBox()
{
	Setup(5, 9, 200, sf::Vector2f(0, 0));
}

TextBox::TextBox(int lVisible, int lCharSize, int lWidth, sf::Vector2f lScreenPos)
{
	Setup(lVisible, lCharSize, lWidth, lScreenPos);
}

TextBox::~TextBox()
{
	Clear();
}

void TextBox::Setup(int lVisible, int lCharSize, int lWidth, sf::Vector2f lScreenPos)
{
	mNumVisible = lVisible;

	sf::Vector2f lOffset(2.0f, 2.0f);
	mFont.loadFromFile("Deps/Amatic-Bold.ttf");
	mContent.setFont(mFont);
	mContent.setString("");
	mContent.setCharacterSize(lCharSize);
	mContent.setFillColor(sf::Color::White);
	mContent.setPosition(lScreenPos + lOffset);
	mBackDrop.setSize(sf::Vector2f(lWidth, (lVisible * (lCharSize * 1.0f))));
	mBackDrop.setFillColor(sf::Color(90, 90, 90, 90));
	mBackDrop.setPosition(lScreenPos);
}

void TextBox::Add(std::string lMessage)
{
	mMessages.push_back(lMessage);
	if (mMessages.size() < 6)
	{
		return;
	}

	mMessages.erase(mMessages.begin());
}

void TextBox::Clear()
{
	mMessages.clear();
}

void TextBox::Render(sf::RenderWindow & lWind)
{
	std::string lContent;

	for (auto &itr : mMessages)
	{
		lContent.append(itr + "\n");
	}

	if (lContent != "")
	{
		mContent.setString(lContent);
		lWind.draw(mBackDrop);
		lWind.draw(mContent);
	}
}
