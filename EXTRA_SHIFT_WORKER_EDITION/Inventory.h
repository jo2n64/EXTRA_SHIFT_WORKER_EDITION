#pragma once
#include <map>
#include "Item.h"
#include <string> //wtf?
#include <SFML/Graphics.hpp>
class Inventory
{
private:
	std::vector<Item*> m_items;
	std::vector<sf::Vector2f> m_itemPositions;
	sf::Sprite m_inventorySprite;
	sf::Text m_descriptionText;
	ItemType m_currentItemHeld;


	void pollItemEvents(Item* item, sf::Event event, sf::Vector2i mousePos);
	//clock? shouldnt it be part of Game instead?
public:
	Inventory();
	~Inventory();
	void addItem(Item* item);
	void removeItem(Item* item);
	void pollEvent(sf::Event event, sf::Vector2i mousePos);
	void update(float dt);
	void draw(sf::RenderWindow* window);
	void setCurrentItemHeld(const ItemType type);
	void refreshItemPositions();
	int getInventorySize() const;
	Item* getItemByType(ItemType type);

	ItemType getCurrentItemHeld() const;

};

