#pragma once
#include <vector>
#include "TextureManager.h"
#include "SoundManager.h"
#include "Button.h"
#include "ItemButton.h"
#include "InteractablePlace.h"
#include "Item.h"

class Location
{
protected:
	std::vector<sf::Sprite*> m_states;
	std::vector<InteractablePlace*> m_interactablePlaces;
	std::vector<Item*> m_items;
	std::vector<ItemButton*> m_itemButtons;
	std::vector<Button*> m_buttons;
	int m_currentState;

	void pollItemEvents(Item* item, sf::Event event, sf::Vector2i mousePos);
	virtual void updateState() = 0;
public:
	Location();
	virtual ~Location();
	virtual void pollEvent(sf::Event event, sf::Vector2i mousePos);
	virtual void update(float dt, sf::Vector2i mousePos);
	virtual void render(sf::RenderWindow* window);
	void setCurrentState(const int currentState);

	int getCurrentState() const;
};

