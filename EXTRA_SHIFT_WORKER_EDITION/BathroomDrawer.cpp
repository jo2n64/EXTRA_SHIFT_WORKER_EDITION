#include "BathroomDrawer.h"

#include <iostream>

#include "Game.h"
#include "EyeDrops.h"

//public funcs
BathroomDrawer::BathroomDrawer() : m_downDrawerOpen(false), m_upperDrawerOpen(false), m_isDownDrawerUnlocked(false)
{

	m_states.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/bathroom/bathroom_closeup_closed.png")));
	m_buttons.push_back(new Button("../assets/graphics/downArrow.png", "Bathroom", sf::Vector2f(100.f, 768 - 150.f)));

	//upper drawer
	m_buttons.push_back(new Button([this](sf::Vector2i mousePos) {openUpperDrawer(); }, sf::Vector2f(1280 / 2.f - 20.f, 150.f), sf::Vector2f(280.f, 185.f), false));
	//bottom drawer
	m_buttons.push_back(new Button([this](sf::Vector2i mousePos) {openLowerDrawer(); }, sf::Vector2f(1280 / 2.f - 20.f, 720 / 2.f + 170.f), sf::Vector2f(300.f, 300.f), false));

	setupDrawer("../assets/graphics/bathroom/closeup_open2.png", sf::Vector2f(340.f, -33.f)); //upper drawer
	setupDrawer("../assets/graphics/bathroom/closeup_open.png", sf::Vector2f(350.f, 720 - 478.f)); //bottom drawer

	//upper drawer
	Item* laxatives = new Item("../assets/graphics/items/laxatives.png", ItemType::LAXATIVES, sf::Vector2f(0.f, 0.f));
	m_upperDrawerItems.push_back(new ItemButton([this]() {}, laxatives, "../assets/graphics/items/laxatives.png", sf::Vector2f(700.f, 150.f)));
	m_interactablePlaces.push_back(new EyeDrops(sf::Vector2f(500.f, 60.f)));

	//bottom drawer
	Item* alcohol = new Item("../assets/graphics/items/alcohol.png", ItemType::ALCOHOL, sf::Vector2f(0.f, 0.f));
	Item* bleach = new Item("../assets/graphics/items/bleach.png", ItemType::BLEACH, sf::Vector2f(0.f, 0.f));
	m_downDrawerItems.push_back(new ItemButton([this]() {}, alcohol, "../assets/graphics/items/alcohol.png", sf::Vector2f(600.f, 600.f)));
	m_downDrawerItems.push_back(new ItemButton([this]() {}, bleach, "../assets/graphics/items/bleach.png", sf::Vector2f(600.f, 600.f)));
}

BathroomDrawer::~BathroomDrawer() = default;

void BathroomDrawer::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	//Location::pollEvent(event, mousePos);

	for (const auto button : m_buttons) {
		button->pollEvent(event, mousePos);
	}

	if (m_upperDrawerOpen)
	{
		for (auto item : m_upperDrawerItems)
		{
			item->pollEvent(event, mousePos);
		}
		m_interactablePlaces[0]->pollEvent(event, mousePos);
	}

	if (m_downDrawerOpen)
	{
		for (auto item : m_downDrawerItems)
		{
			item->pollEvent(event, mousePos);
		}
		//m_interactablePlaces[1]->pollEvent(event, mousePos);
	}
}

void BathroomDrawer::render(sf::RenderWindow * window)
{
	window->draw(*m_states[m_currentState]);

	for (const auto button : m_buttons) {
		button->draw(window);
	}
	if (m_upperDrawerOpen)
	{
		window->draw(*m_drawers[0]);
		for (auto item : m_upperDrawerItems)
		{
			item->draw(window);
		}
		m_interactablePlaces[0]->draw(window); //eyedrops
	}
	if (m_downDrawerOpen)
	{
		window->draw(*m_drawers[1]);
		for (auto item : m_downDrawerItems)
		{
			item->draw(window);
		}
		m_interactablePlaces[1]->draw(window); // meds
	}
}

void BathroomDrawer::update(float dt, sf::Vector2i mousePos)
{
	for (const auto button : m_buttons) {
		button->update(dt);
	}
	if (m_upperDrawerOpen)
	{
		for (auto item : m_upperDrawerItems)
		{
			item->update(dt, mousePos);
		}
		m_interactablePlaces[0]->update(dt);
	}
	if (m_downDrawerOpen)
	{
		for (auto item : m_downDrawerItems)
		{
			item->update(dt, mousePos);
		}
		//m_interactablePlaces[1]->update(dt);
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
	sf::Sprite* drawerSpr = new sf::Sprite(TextureManager::GetTexture(texturePath));
	drawerSpr->setPosition(position);
	m_drawers.push_back(drawerSpr);

}
