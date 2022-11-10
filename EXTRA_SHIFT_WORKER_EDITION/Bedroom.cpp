#include "Bedroom.h"
#include <iostream>

//public funcs
Bedroom::Bedroom() : Location()
{
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bedroom/room_bookshelf.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bedroom/room_usescrewdriver.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bedroom/room_safe.png")));

	m_buttons.push_back(new Button("Kitchen", sf::Vector2f(1280.f - 50.f, 768 / 2.f - 75.f), sf::Vector2f(100.f, 100.f), false));
}

Bedroom::~Bedroom()
{
}

void Bedroom::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	Location::pollEvent(event, mousePos);
}

//private funcs
void Bedroom::updateState()
{
}
