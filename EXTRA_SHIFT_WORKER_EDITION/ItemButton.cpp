#include "ItemButton.h"
#include "TextureManager.h"
#include "Game.h"
#include "Item.h"
#include "Location.h"
#include <iostream>


ItemButton::ItemButton(std::function<void()> callback, Item* itemToAdd, std::string texturePath, sf::Vector2f position, bool isDrawing, bool isClickable) :
	m_isInBounds(false),
	m_itemToAdd(itemToAdd),
	m_isClickable(isClickable),
	m_isDrawing(isDrawing),
	m_position(position),
	m_callback(callback)
{
	m_texture = TextureManager::GetTexture(texturePath);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2.f, m_texture.getSize().y / 2.f);
	m_sprite.setPosition(m_position);
}

ItemButton::ItemButton(std::function<void()> callback, Item* itemToAdd, sf::Vector2f position, sf::Vector2f size, bool isDrawing, bool isClickable) :
	m_isInBounds(false),
	m_itemToAdd(itemToAdd),
	m_isClickable(isClickable),
	m_isDrawing(isDrawing),
	m_position(position),
	m_callback(callback)
{
	m_texture = TextureManager::GetTexture("../assets/graphics/debug.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(size.x, size.y)));
	m_sprite.setOrigin(m_texture.getSize().x / 2.f, m_texture.getSize().y / 2.f);
	m_sprite.setPosition(m_position);
}

ItemButton::~ItemButton()
{
}

void ItemButton::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	if (m_isClickable)
	{
		if (event.type == sf::Event::MouseButtonPressed) {
			if (m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y) && event.mouseButton.button == sf::Mouse::Left) {
				addItemToInventory(m_itemToAdd);
				m_callback();
			}
		}
	}

}

void ItemButton::update(float dt, sf::Vector2i mousePos)
{
	m_isInBounds = m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

void ItemButton::draw(sf::RenderWindow* window)
{
	if (m_isDrawing)
	{
		window->draw(m_sprite);
	}
}

void ItemButton::setIsDrawing(const bool isDrawing)
{
	m_isDrawing = isDrawing;
}

void ItemButton::setIsClickable(const bool isClickable)
{
	m_isClickable = isClickable;
}

sf::Sprite ItemButton::getSprite() const
{
	return m_sprite;
}

bool ItemButton::getIsInBounds() const
{
	return m_isInBounds;
}

void ItemButton::addItemToInventory(Item* item)
{
	Game::getInstance()->getInventory()->addItem(item);
	item->setIsInInventory(true);
	m_isClickable = false;
	m_isDrawing = false;
	std::cout << "Added item: " << ToString(item->getType()) << " to inventory" << std::endl;
}
