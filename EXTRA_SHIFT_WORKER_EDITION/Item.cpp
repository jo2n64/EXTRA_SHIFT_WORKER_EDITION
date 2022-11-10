#include "Item.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>

Item::Item(std::string texturePath, ItemType type, sf::Vector2f position, int uses)
{
	m_sprite.setTexture(TextureManager::GetTexture(texturePath));
	sf::FloatRect spriteBounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin(spriteBounds.width / 2.f, spriteBounds.height / 2.f);
	m_isInInventory = false;
	m_isHeld = false;
	m_type = type;
	m_uses = uses; //TODO assign uses like you should
	setPosition(position);
}

Item::~Item()
{
}

void Item::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	if (event.type = sf::Event::MouseMoved)
	{
		if (m_isHeld && Game::getInstance()->getInventory()->getCurrentItemHeld() == m_type)
		{
			setPosition(static_cast<sf::Vector2f>(mousePos));
		}
	}
}

void Item::update(float dt)
{
	if (m_isHeld)
	{

		return;
	}
}

void Item::draw(sf::RenderWindow* window)
{
	window->draw(m_sprite);
}

void Item::setPosition(const sf::Vector2f position)
{
	m_position = position;
	m_sprite.setPosition(position);
}

void Item::setIsHeld(const bool isHeld)
{
	m_isHeld = isHeld;
}

void Item::setIsInInventory(const bool isInInventory)
{
	m_isInInventory = isInInventory;
}

sf::Vector2f Item::getPosition() const
{
	return m_position;
}

int Item::getUses() const
{
	return m_uses;
}

void Item::setUses(const int uses)
{
	m_uses = uses;
}

bool Item::getIsInInventory() const
{
	return m_isInInventory;
}

bool Item::getIsHeld() const
{
	return m_isHeld;
}

ItemType Item::getType() const
{
	return m_type;
}

sf::Sprite* Item::getSprite()
{
	return &m_sprite;
}

