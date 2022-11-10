#include "Kitchen.h"

//public funcs
Kitchen::Kitchen() : Location()
{
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/kitchen/kitchen.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/kitchen/kitchen.explode_screwoutTV.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/kitchen/kitchen.explode_screwinTV.png")));


	m_buttons.push_back(new Button("Bedroom", sf::Vector2f(240.f, 898 / 2.f - 120.f), sf::Vector2f(150.f, 400.f), false, false));
	m_buttons.push_back(new Button("Corridor", sf::Vector2f(1280 / 2.f, 898 / 2.f + 160.f), sf::Vector2f(150.f, 150.f), false));
	m_buttons.push_back(new Button("KitchenOven", sf::Vector2f(260.f, 898 / 2.f + 100.f), sf::Vector2f(250.f, 250.f), false));


}

Kitchen::~Kitchen()
= default;

void Kitchen::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	Location::pollEvent(event, mousePos);
}

//private funcs
void Kitchen::updateState()
{
}
