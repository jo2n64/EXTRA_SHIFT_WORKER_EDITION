#include "InteractablePlace.h"

InteractablePlace::InteractablePlace(std::string name, sf::Vector2f position)
{
	m_name = name;
	m_position = position;
	m_finished = false;
}

InteractablePlace::~InteractablePlace()
{
	for(const auto state : m_placeStates)
	{
		delete state;
	}
}

void InteractablePlace::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
}

void InteractablePlace::update(float dt)
{
}

void InteractablePlace::draw(sf::RenderWindow* window)
{
	window->draw(*m_placeStates[m_currentState]);
}

void InteractablePlace::setCurrentState(const int currentState)
{
	m_currentState = currentState;
}

int InteractablePlace::getCurrentState() const
{
	return m_currentState;
}

void InteractablePlace::setFinished(const bool finished)
{
	m_finished = finished;
}

bool InteractablePlace::getFinished() const
{
	return m_finished;
}

std::string InteractablePlace::getName() const
{
	return m_name;
}
