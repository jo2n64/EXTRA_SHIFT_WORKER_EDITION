#include "Kitchen.h"
#include <iostream>

//public funcs
Kitchen::Kitchen() : Location()
{
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/kitchen/kitchen.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/kitchen/kitchen.explode_screwoutTV.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/kitchen/kitchen.explode_screwinTV.png")));


	m_buttons.push_back(new Button("Bedroom", sf::Vector2f(240.f, 898 / 2.f - 120.f), sf::Vector2f(150.f, 400.f), false, false));
	m_buttons.push_back(new Button("Corridor", sf::Vector2f(1280 / 2.f, 898 / 2.f + 160.f), sf::Vector2f(150.f, 150.f), false));
	m_buttons.push_back(new Button("KitchenOven", sf::Vector2f(260.f, 898 / 2.f + 100.f), sf::Vector2f(250.f, 250.f), false));

	Item* matches = new Item("../assets/graphics/items/matches.png", ItemType::MATCHES);
	m_itemButtons.push_back(new ItemButton([this]() {std::cout << "aaa" << std::endl; }, matches, "../assets/graphics/items/matchestopick.png", sf::Vector2f(1280.f - 290.f, 550.f)));
	Item* screwdriver = new Item("../assets/graphics/items/screwdriver2.png", ItemType::SCREWDRIVER);
	m_itemButtons.push_back(new ItemButton([this]() {updateState(); }, screwdriver, sf::Vector2f(1360.f, 665.f), sf::Vector2f(70.f, 20.f)));


}

Kitchen::~Kitchen()
= default;

void Kitchen::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	//TODO change it up to poll events during different states
	Location::pollEvent(event, mousePos);
}

//private funcs
void Kitchen::updateState()
{
	m_currentState = 1;
}
