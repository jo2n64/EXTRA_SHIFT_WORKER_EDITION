#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Item;

class ItemButton
{
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	bool m_isDrawing;
	bool m_isClickable;
	bool m_isInBounds;
	Item* m_itemToAdd;


	std::function<void()> m_callback;

	void addItemToInventory(Item* item);

public:
	ItemButton(std::function<void()> callback, Item* itemToAdd, std::string texturePath, sf::Vector2f position, bool isDrawing = true, bool isClickable = true); // for arrows
	ItemButton(std::function<void()> callback, Item* itemToAdd, sf::Vector2f position, sf::Vector2f size, bool isDrawing = true, bool isClickable = true); //for debug buttons/buttons drawn on the location
	~ItemButton();
	void pollEvent(sf::Event event, sf::Vector2i mousePos);
	void update(float dt, sf::Vector2i mousePos);
	void draw(sf::RenderWindow* window);

	void setIsDrawing(const bool isDrawing);
	void setIsClickable(const bool isClickable);

	sf::Sprite getSprite() const;
	bool getIsInBounds() const;
};

