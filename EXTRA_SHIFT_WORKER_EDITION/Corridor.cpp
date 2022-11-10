#include "Corridor.h"
#include <iostream>
#include <functional>

//public funcs
Corridor::Corridor() : Location()
{
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/corridor/hallway_closed.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/corridor/hallway.png")));


	m_buttons.push_back(new Button("Bathroom", sf::Vector2f(200.f, 720 / 2.f - 165.f), sf::Vector2f(200.f, 550.f), false, true));
	m_buttons.push_back(new Button("Kitchen", sf::Vector2f(1280 / 2.f - 70.f, 720 / 2.f - 70.f), sf::Vector2f(200.f, 400.f), false, true));

	m_buttons.push_back(new Button([this](sf::Vector2i mousePos) {openCloset(mousePos); }, sf::Vector2f(1280 - 260.f, 898 / 2.f - 150.f), sf::Vector2f(250.f, 420.f), false));

	Item* fireworks = new Item("../assets/graphics/items/fireworks_item.png", ItemType::FIREWORKS, sf::Vector2f(0, 0), 1);
	Item* catnip = new Item("../assets/graphics/items/catnip_item.png", ItemType::CATNIP, sf::Vector2f(0, 0), 1);
	m_itemButtons.push_back(new ItemButton([this]() {updateState(); }, fireworks, "../assets/graphics/items/fireworks_item.png", sf::Vector2f(1280 / 2.f + 320.f, 898 / 2.f + 120.f)));
	m_itemButtons.push_back(new ItemButton([this]() {updateState(); }, catnip, "../assets/graphics/items/catnip_item.png", sf::Vector2f(1280.f - 200.f, 898 / 2.f + 120.f)));

}

Corridor::~Corridor() = default;

void Corridor::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	for (const auto button : m_buttons) {
		button->pollEvent(event, mousePos);
	}
	if (m_currentState == 1) {
		for (const auto itemButton : m_itemButtons)
		{
			itemButton->pollEvent(event, mousePos);
		}
	}
}

void Corridor::render(sf::RenderWindow * window)
{
	window->draw(*m_states[m_currentState]);
	for (const auto button : m_buttons) {
		button->draw(window);
	}
	if (m_currentState == 1)
	{
		for (const auto itemButton : m_itemButtons)
		{
			itemButton->draw(window);
		}
	}
}

void Corridor::update(float dt, sf::Vector2i mousePos)
{
	Location::update(dt, mousePos);
}

void Corridor::openCloset(sf::Vector2i mousePos)
{
	//doesnt work properly, TODO fix
	if(m_currentState == 1){
		for (auto item : m_itemButtons)
		{
			if (item->getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y))
			{
				return;
			}
		}
	}
	m_currentState = m_currentState == 1 ? 0 : 1;

}

//private funcs
void Corridor::updateState()
{
}