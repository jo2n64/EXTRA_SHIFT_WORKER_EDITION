#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum class CursorState
{
	POINT,
	GRAB,
	LOOK
};

class Cursor
{
private:
	sf::Vector2f m_position;
	std::vector<sf::Sprite*> m_sprites;
	CursorState m_state;
public:
	Cursor();
	~Cursor();
	void pollEvent(sf::Event event);
	void update(float dt, sf::Vector2i mousePos);
	void draw(sf::RenderWindow* window);
	void setCursorState(CursorState state);
};

