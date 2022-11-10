#include "Inventory.h"

#include <cassert>

#include "TextureManager.h"
#include <iostream>
Inventory::Inventory()
{
	m_inventorySprite.setTexture(TextureManager::GetTexture("../assets/graphics/inventory.png"));
	m_inventorySprite.setPosition(0.f, 898.f - 178.f);

}

Inventory::~Inventory()
{
	for (auto item : m_items)
	{
		delete item;
	}
}

void Inventory::addItem(Item* item)
{
	m_items.push_back(item);
	int itemCount = m_items.size();
	refreshItemPositions();
}

void Inventory::removeItem(Item* item)
{
	for (int i = 0; i < m_items.size(); i++)
	{
		if (m_items[i]->getType() == item->getType())
		{
			m_items.erase(m_items.begin() + i);
		}
	}
}

void Inventory::pollEvent(sf::Event event, sf::Vector2i mousePos)
{

	for (auto item : m_items)
	{
		item->pollEvent(event, mousePos);

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (!item->getIsHeld() && item->getSprite()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					setCurrentItemHeld(item->getType());
					item->setIsHeld(true);
				}
				else
				{
					item->setIsHeld(false);
					refreshItemPositions();
					setCurrentItemHeld(ItemType::NONE);
				}
			}

		}
	}
}

void Inventory::update(float dt)
{
	for (auto item : m_items)
	{
		item->update(dt);
		if (item->getUses() <= 0)
		{
			item->setIsInInventory(false);
			removeItem(item);
			refreshItemPositions();
		}
	}
}

void Inventory::draw(sf::RenderWindow* window)
{
	window->draw(m_inventorySprite);
	for (auto item : m_items)
	{
		item->draw(window);
	}
}

void Inventory::setCurrentItemHeld(const ItemType type)
{
	m_currentItemHeld = type;
}

void Inventory::refreshItemPositions()
{
	for (int i = 0; i < m_items.size(); i++)
	{
		m_items[i]->setPosition(sf::Vector2f(230.f + i * 150.f, 898.f - 60.f));
	}

}

int Inventory::getInventorySize() const
{
	return m_items.size();
}

Item* Inventory::getItemByType(ItemType type)
{
	for(const auto item : m_items)
	{
		if (item->getType() == type)
		{
			return item;
		}
		return nullptr;
	}
}

ItemType Inventory::getCurrentItemHeld() const
{
	return m_currentItemHeld;
}
