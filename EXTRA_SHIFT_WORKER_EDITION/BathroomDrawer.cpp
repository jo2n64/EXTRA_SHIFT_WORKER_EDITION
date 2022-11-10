#include "BathroomDrawer.h"

#include <iostream>

#include "Game.h"

//public funcs
BathroomDrawer::BathroomDrawer() : m_downDrawerOpen(false), m_upperDrawerOpen(false), m_isDownDrawerUnlocked(false)
{

	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bathroom/bathroom_closeup_closed.png")));

	m_buttons.push_back(new Button("../assets/graphics/downArrow.png", "Bathroom", sf::Vector2f(100.f, 768 - 150.f)));

	//upper drawer - prolly should've turned to a class
	m_buttons.push_back(new Button([this](sf::Vector2i mousePos) {openUpperDrawer(); }, sf::Vector2f(1280 / 2.f - 20.f, 150.f), sf::Vector2f(280.f, 185.f), false));
	//upper drawer
	setupDrawer("../assets/graphics/bathroom/closeup_open2.png", sf::Vector2f(340.f, -33.f));

	//TODO finish setting the items and interactable places up
	Item* laxatives = new Item("../assets/graphics/items/laxatives.png", ItemType::LAXATIVES, sf::Vector2f(0.f, 0.f));
	m_upperDrawerItems.push_back(ItemButton([this]() {}, laxatives, "../assets/graphics/items/laxatives.png", sf::Vector2f(100.f, 100.f)));


	//lower drawer - same for this
	m_buttons.push_back(new Button([this](sf::Vector2i mousePos) {openLowerDrawer(); }, sf::Vector2f(1280 / 2.f - 20.f, 720 / 2.f + 170.f), sf::Vector2f(300.f, 300.f), false));
	//lower drawer
	setupDrawer("../assets/graphics/bathroom/closeup_open.png", sf::Vector2f(350.f,720 - 478.f));
}

BathroomDrawer::~BathroomDrawer() = default;

void BathroomDrawer::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	Location::pollEvent(event, mousePos);

	if (m_upperDrawerOpen)
	{
		for (auto item : m_upperDrawerItems)
		{
			item.pollEvent(event, mousePos);
		}
	}
	if (m_downDrawerOpen)
	{
		for (auto item : m_downDrawerItems)
		{
			item.pollEvent(event, mousePos);
		}
	}
}

void BathroomDrawer::render(sf::RenderWindow* window)
{
	Location::render(window);

	if(m_upperDrawerOpen)
	{
		window->draw(m_drawers[0]);
		for(auto item : m_upperDrawerItems)
		{
			item.draw(window);
		}
	}
	if(m_downDrawerOpen)
	{
		window->draw(m_drawers[1]);
		for(auto item : m_downDrawerItems)
		{
			item.draw(window);
		}
	}
}

void BathroomDrawer::update(float dt, sf::Vector2i mousePos)
{
	Location::update(dt, mousePos);

	if (m_upperDrawerOpen)
	{
		for (auto item : m_upperDrawerItems)
		{
			item.update(dt, mousePos);
		}
	}
	if (m_downDrawerOpen)
	{
		for (auto item : m_downDrawerItems)
		{
			item.update(dt, mousePos);
		}
	}
}

//private funcs
void BathroomDrawer::updateState()
{
}

void BathroomDrawer::openUpperDrawer()
{
	m_upperDrawerOpen = !m_upperDrawerOpen;
}

void BathroomDrawer::openLowerDrawer()
{
	//add requirement for ze key
	if (Game::getInstance()->getInventory()->getCurrentItemHeld() == ItemType::KEY) {
		m_isDownDrawerUnlocked = true;
		Game::getInstance()->getInventory()->getItemByType(ItemType::KEY)->setUses(0);
		std::cout << Game::getInstance()->getInventory()->getInventorySize() << std::endl;
	}
	if (m_isDownDrawerUnlocked)
	{
		m_downDrawerOpen = !m_downDrawerOpen;
	}
}

void BathroomDrawer::setupDrawer(std::string texturePath, sf::Vector2f position)
{
	sf::Sprite drawerSpr = sf::Sprite(TextureManager::GetTexture(texturePath));
	drawerSpr.setPosition(position);
	m_drawers.push_back(drawerSpr);

}
