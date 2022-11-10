#pragma once
#include <SFML/Graphics.hpp>

enum class ItemType
{
	NONE,
	AXE,
	FIREWORKS,
	MATCHES,
	KEY,
	VITAMINS,
	CATNIP,
	ALCOHOL,
	LAXATIVES,
	BLEACH,
	SCREWDRIVER
};

inline const std::string ToString(ItemType type)
{
	switch (type)
	{
	case ItemType::NONE:
		return "None";
		break;
	case ItemType::AXE:
		return "Axe";
		break;
	case ItemType::FIREWORKS:
		return "Fireworks";
		break;
	case ItemType::MATCHES:
		return "Matches";
		break;
	case ItemType::KEY:
		return "Key";
		break;
	case ItemType::VITAMINS:
		return "Vitamins";
		break;
	case ItemType::CATNIP:
		return "Catnip";
		break;
	case ItemType::ALCOHOL:
		return "Alcohol";
		break;
	default:
		return "Item doesn't exist!";
		break;
	}
}
class Item
{
private:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	ItemType m_type;
	bool m_isInInventory;
	bool m_isHeld;
	int m_uses;


public:
	Item(std::string texturePath, ItemType type, sf::Vector2f position = sf::Vector2f(0.f, 0.f), int uses = 20);
	~Item();
	void pollEvent(sf::Event event, sf::Vector2i mousePos);
	void update(float dt);
	void draw(sf::RenderWindow* window);
	void setPosition(const sf::Vector2f position);
	void setIsHeld(const bool isHeld);
	void setIsInInventory(const bool isInInventory);

	sf::Vector2f getPosition() const;
	int getUses() const;
	void setUses(const int uses);

	bool getIsInInventory() const;
	bool getIsHeld() const; //not sure if this is needed actually...
	ItemType getType() const;
	sf::Sprite* getSprite();
};


