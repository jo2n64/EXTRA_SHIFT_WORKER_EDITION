#include "Bathroom.h"


//public funcs
Bathroom::Bathroom()
{
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bathroom/bathroom.png")));


	m_buttons.push_back(new Button("BathroomDrawer", sf::Vector2f(1280 / 2.f + 50.f, 898 / 2.f - 175.f), sf::Vector2f(200.f, 350.f), false));
	m_buttons.push_back(new Button("Corridor", sf::Vector2f(1280 / 2.f, 898 / 2.f + 200.f), sf::Vector2f(200.f, 170.f), false));
}

Bathroom::~Bathroom() = default;

void Bathroom::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	Location::pollEvent(event, mousePos);
}

//private funcs
void Bathroom::updateState()
{
}