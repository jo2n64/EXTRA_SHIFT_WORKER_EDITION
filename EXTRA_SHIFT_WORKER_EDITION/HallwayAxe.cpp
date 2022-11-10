#include "HallwayAxe.h"



HallwayAxe::HallwayAxe()
{
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/hallway/axelocation.png")));
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/hallway/axelocation_gone.png")));


	m_buttons.push_back(new Button("Hallway", sf::Vector2f(60.f, 720 / 2.f + 10.f), sf::Vector2f(100.f, 100.f), false));

	Item* axe = new Item("../assets/graphics/items/axe.png", ItemType::AXE, sf::Vector2f(0,0), 4);
	m_itemButtons.push_back(new ItemButton([this]() {updateState(); }, axe, sf::Vector2f(1280 / 2.f + 420.f, 898 / 2.f + 80.f), sf::Vector2f(300.f, 220.f), false));
}

HallwayAxe::~HallwayAxe() = default;

void HallwayAxe::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	Location::pollEvent(event, mousePos);
}


//private funcs
void HallwayAxe::updateState()
{
	setCurrentState(1);
}