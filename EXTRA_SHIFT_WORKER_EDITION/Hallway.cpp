#include "Hallway.h"
#include "Door.h"


//public funcs
Hallway::Hallway()
{
	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/hallway/maindoor.png")));


	m_buttons.push_back(new Button("HallwayAxe", sf::Vector2f(1280.f - 100.f, 370.f), sf::Vector2f(130.f, 110.f), false));
	m_buttons.push_back(new Button("Corridor", sf::Vector2f(1280 / 2.f - 20.f, 220.f), sf::Vector2f(300.f, 600.f), false, false));

	m_interactablePlaces.push_back(new Door());
	
}

Hallway::~Hallway() = default;

void Hallway::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	Location::pollEvent(event, mousePos);
}

void Hallway::update(float dt, sf::Vector2i mousePos)
{
	Location::update(dt, mousePos);
	if(m_interactablePlaces[0]->getFinished())
	{
		m_buttons[1]->setIsClickable(true);
	}
}


//private funcs
void Hallway::updateState()
{
}