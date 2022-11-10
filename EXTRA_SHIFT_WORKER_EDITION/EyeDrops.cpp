#include "EyeDrops.h"

#include "Game.h"

EyeDrops::EyeDrops(sf::Vector2f position) : InteractablePlace("EyeDrops", position)
{
	m_placeStates.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bathroom/eyedrops.png")));
	m_placeStates.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bathroom/eyedrops_bleach.png")));

	for (const auto state : m_placeStates)
	{
		state->setPosition(m_position);
	}

	m_itemsRequired.push_back(ItemType::BLEACH);

}

EyeDrops::~EyeDrops() = default;

void EyeDrops::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	//prolly set it at the abstract class, ur repeating urself
	//InteractablePlace::pollEvent(event, mousePos);
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

void EyeDrops::draw(sf::RenderWindow* window)
{
	InteractablePlace::draw(window);
}
