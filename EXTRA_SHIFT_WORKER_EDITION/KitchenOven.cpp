#include "KitchenOven.h"


//public funcs
KitchenOven::KitchenOven()
{
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/kitchenoven/oven.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/kitchenoven/oven_fireworks.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/kitchenoven/oven_fireworks_lit.png")));

	m_buttons.push_back(new Button("../assets/graphics/downArrow.png", "Kitchen", sf::Vector2f(150.f, 768 - 200.f)));
}

KitchenOven::~KitchenOven() = default;

void KitchenOven::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	Location::pollEvent(event, mousePos);
}

//private funcs
void KitchenOven::updateState()
{
}