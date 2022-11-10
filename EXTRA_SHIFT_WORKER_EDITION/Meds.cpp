#include "Meds.h"

#include "Game.h"

Meds::Meds(sf::Vector2f position) : InteractablePlace("Meds", position)
{
	m_placeStates.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bathroom/meds_okay.png")));
	m_placeStates.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bathroom/meds_changed.png")));

	for (const auto state : m_placeStates)
	{
		state->setPosition(m_position);
	}
	m_placeStates[1]->setPosition(m_position.x, m_position.y - 20.f);

	m_itemsRequired.push_back(ItemType::VITAMINS);
}

Meds::~Meds()
{
}

void Meds::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
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

void Meds::draw(sf::RenderWindow* window)
{
	InteractablePlace::draw(window);
}
