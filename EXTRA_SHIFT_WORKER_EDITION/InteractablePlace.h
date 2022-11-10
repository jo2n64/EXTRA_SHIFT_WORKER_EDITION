#pragma once
#include "Item.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
class InteractablePlace
{
protected:
	std::vector<ItemType> m_itemsRequired;
	sf::Vector2f m_position;
	std::vector<sf::Sprite*> m_placeStates;
	std::string m_name;
	int m_currentState;
	bool m_finished;

public:
	InteractablePlace(std::string name, sf::Vector2f position);
	~InteractablePlace();

	virtual void pollEvent(sf::Event event, sf::Vector2i mousePos);
	void update(float dt);
	virtual void draw(sf::RenderWindow* window);

	void setCurrentState(const int currentState);
	int getCurrentState() const;

	void setFinished(const bool finished);
	bool getFinished() const;

	std::string getName() const;

};

