#include "Door.h"
#include "Game.h"

Door::Door() : InteractablePlace("Door", sf::Vector2f(0,15))
{
	m_itemsRequired.push_back(ItemType::AXE);

	m_placeStates.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/hallway/door_fine.png")));
	m_placeStates.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/hallway/door_harmed1.png")));
	m_placeStates.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/hallway/door_harmed2.png")));
	m_placeStates.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/hallway/door_harmed3.png")));

	for(auto state : m_placeStates)
	{
		state->setPosition(m_position);
	}
}

void Door::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	InteractablePlace::pollEvent(event, mousePos);
	auto itemHeld = Game::getInstance()->getInventory()->getCurrentItemHeld();
	auto item = Game::getInstance()->getInventory()->getItemByType(itemHeld);

	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (!m_finished) {
				for (auto type : m_itemsRequired)
				{
					if (type == itemHeld && m_placeStates[m_currentState]->getGlobalBounds().contains(mousePos.x, mousePos.y))
					{
						int itemUsesLeft = item->getUses();
						itemUsesLeft--;
						item->setUses(itemUsesLeft);
						m_currentState++;
						if (m_currentState == m_placeStates.size())
						{
							m_finished = true;
						}
					}
				}
			}
		}
	}
}

void Door::draw(sf::RenderWindow* window)
{
	if(!m_finished)
	{
		window->draw(*m_placeStates[m_currentState]);
	}
}
