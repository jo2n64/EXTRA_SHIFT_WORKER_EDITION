#include "Location.h"
#include "Inventory.h"
#include "Game.h"
#include <iostream>


Location::Location()
{
	m_currentState = 0;
	for (auto state : m_states)
	{
		sf::Vector2f statePos = state->getPosition();
		state->setPosition(statePos.x, statePos.y - 300.f);
	}
}

Location::~Location()
{
	for (const auto state : m_states) {
		delete state;
	}
	for (const auto iPlace : m_interactablePlaces) {
		delete iPlace;
	}
	for(const auto item : m_items)
	{
		delete item;
	}
	for (const auto itemButton : m_itemButtons) {
		delete itemButton;
	}
	for (const auto button : m_buttons) {
		delete button;
	}
}

void Location::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	for (const auto button : m_buttons) {
		button->pollEvent(event, mousePos);
	}

	for(const auto iPlace : m_interactablePlaces)
	{
		iPlace->pollEvent(event, mousePos);
	}

	for(const auto item : m_items)
	{
		item->pollEvent(event, mousePos);
		pollItemEvents(item, event, mousePos);
	}

	for(const auto itemButton : m_itemButtons)
	{
		itemButton->pollEvent(event, mousePos);
	}
}

void Location::pollItemEvents(Item* item, sf::Event event, sf::Vector2i mousePos)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (item->getSprite()->getGlobalBounds().contains(mousePos.x, mousePos.y))
			{
				if (!item->getIsInInventory())
				{
					Game::getInstance()->getInventory()->addItem(item);
					item->setIsInInventory(true);
				}
			}
		}
	}
}


void Location::update(const float dt, sf::Vector2i mousePos)
{
	for (const auto button : m_buttons) {
		button->update(dt);
	}
	for (const auto iPlace : m_interactablePlaces)
	{
		iPlace->update(dt);
	}
	for(const auto item : m_items)
	{
		item->update(dt);
	}

	for(const auto itemButton : m_itemButtons)
	{
		itemButton->update(dt, mousePos);
	}
}

void Location::render(sf::RenderWindow* window)
{
	//render the location and its current state
	window->draw(*m_states[m_currentState]);
	for (const auto button : m_buttons) {
		button->draw(window);
	}
	for(const auto iPlace : m_interactablePlaces)
	{
		iPlace->draw(window);
	}
	for(const auto item : m_items)
	{
		item->draw(window);
	}
	for(const auto itemButton : m_itemButtons)	{
		itemButton->draw(window);
	}
}

void Location::setCurrentState(const int currentState)
{
	m_currentState = currentState;
}

int Location::getCurrentState() const
{
	return m_currentState;
}
