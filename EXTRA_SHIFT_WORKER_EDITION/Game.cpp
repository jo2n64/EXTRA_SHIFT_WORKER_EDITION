#include "Game.h"
#include "Kitchen.h"
#include "Corridor.h"
#include "Bedroom.h"
#include "Hallway.h"
#include "HallwayAxe.h"
#include "KitchenOven.h"
#include "Bathroom.h"
#include "BathroomDrawer.h"
#include "Item.h"

#include <assert.h>
#include <iostream>
Game* Game::m_Instance = nullptr;


Game::Game(int width, int height)
{
	assert(m_Instance == nullptr);
	m_Instance = this;

	m_window = new sf::RenderWindow(sf::VideoMode(width, height), "sample name", sf::Style::Default);

	//m_soundManager.playTestSound();

	m_clock.restart();

	m_locations["Kitchen"] = new Kitchen();
	m_locations["Bedroom"] = new Bedroom();
	m_locations["Corridor"] = new Corridor();
	m_locations["Hallway"] = new Hallway();
	m_locations["HallwayAxe"] = new HallwayAxe();
	m_locations["KitchenOven"] = new KitchenOven();
	m_locations["Bathroom"] = new Bathroom();
	m_locations["BathroomDrawer"] = new BathroomDrawer();


	m_currentLocation = "BathroomDrawer";

	m_gameState = GameState::PLAYING;

	//m_inventory.addItem(new Item("../assets/graphics/items/axe.png", ItemType::AXE));
	//m_inventory.refreshItemPositions();

	m_window->setMouseCursorVisible(false);


	
}

void Game::pollEvents(sf::Event event)
{
	m_soundManager.pollEvent(event);
	m_mousePos = sf::Mouse::getPosition(*m_window);
	m_cursor.pollEvent(event);
	m_locations[m_currentLocation]->pollEvent(event, m_mousePos);
	m_inventory.pollEvent(event, m_mousePos);
}

void Game::update(float dt)
{
	m_locations[m_currentLocation]->update(dt, m_mousePos);
	m_cursor.update(dt, m_mousePos);
	m_inventory.update(dt);
}

void Game::render()
{
	m_window->clear();
	m_locations[m_currentLocation]->render(m_window);
	m_inventory.draw(m_window);
	m_cursor.draw(m_window);
	m_window->display();
}


Game::~Game()
{
	delete m_window;
}

void Game::run()
{
	while (m_window->isOpen()) {
		m_clock.restart();
		m_dt = m_clock.getElapsedTime().asSeconds();
		sf::Event event;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			m_window->close();
		}
		while (m_window->pollEvent(event)) {
			pollEvents(event);
		}
		update(m_dt);
		render();
	}
}

void Game::setCurrentLocation(std::string newCurrentLocation)
{
	m_currentLocation = newCurrentLocation;
	std::cout << m_currentLocation << std::endl;
}

Game* Game::getInstance()
{
	return m_Instance;
}

Inventory* Game::getInventory()
{
	return &m_inventory;
}

sf::Vector2i Game::getMousePosition() const
{
	return m_mousePos;
}
