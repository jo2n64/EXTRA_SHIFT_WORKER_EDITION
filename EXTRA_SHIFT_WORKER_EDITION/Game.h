#pragma once
#include "SoundManager.h"
#include "TextureManager.h"
#include "Location.h"
#include "InteractablePlace.h"
#include "Cursor.h"
#include "Inventory.h"

/*things to change up:
 *	-change regular pointer to unique_ptr
 *	-change the current location to use the enum rather than string (faster + less error prone)
 *	-do the same for items eventually
 *	-const up your code where needed
*/
enum class GameState {
	PLAYING,
	MAIN_MENU,
	GAME_OVER,
	INTRO
};

//probably add an enum for which room ur in
enum class CurrentLocation {
	HALLWAY,
	HALLWAY_AXE,
	CORRIDOR,
	BATHROOM,
	BATHROOM_DRAWERS,
	KITCHEN,
	KITCHEN_STOVE,
	BEDROOM
};

class Game
{
	static Game* m_Instance;
	std::string m_currentLocation;

	TextureManager m_textureManager;
	SoundManager m_soundManager;
	Inventory m_inventory;

	std::map<std::string, Location*> m_locations;
	sf::Clock m_clock;
	sf::RenderWindow* m_window;

	GameState m_gameState;

	sf::Texture m_sampleTexture;
	sf::Sprite m_sampleSprite;

	sf::Vector2i m_mousePos;

	Cursor m_cursor;

	float m_dt;


	void pollEvents(sf::Event event);
	void update(float dt);
	void render();
public:
	Game(int width, int height);
	~Game();
	void run();
	void setCurrentLocation(std::string newCurrentLocation);
	static Game* getInstance();
	Inventory* getInventory();
	sf::Vector2i getMousePosition() const;

};

