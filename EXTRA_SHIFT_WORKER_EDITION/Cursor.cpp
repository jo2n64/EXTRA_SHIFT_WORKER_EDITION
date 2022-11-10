#include "Cursor.h"
#include "TextureManager.h"
Cursor::Cursor()
{
	m_position = sf::Vector2f(0.f, 0.f);

	m_sprites.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/cursor/pointinghand.png")));
	m_sprites.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/cursor/grabhand.png")));
	m_sprites.push_back(new sf::Sprite(TextureManager::GetTexture("../assets/graphics/cursor/eye.png")));

	for(auto spr: m_sprites)
	{
		spr->setScale(0.15f, 0.15f);
		spr->setOrigin(100.f, 100.f);
	}

	m_state = CursorState::POINT;
}

Cursor::~Cursor()
{
}

void Cursor::pollEvent(sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Num1)
		{
			setCursorState(CursorState::POINT);
		}
		if (event.key.code == sf::Keyboard::Num2)
		{
			setCursorState(CursorState::GRAB);
		}
		if (event.key.code == sf::Keyboard::Num3)
		{
			setCursorState(CursorState::LOOK);
		}
	}
}

void Cursor::update(float dt, sf::Vector2i mousePos)
{
	m_sprites[static_cast<int>(m_state)]->setPosition(static_cast<sf::Vector2f>(mousePos));
}

void Cursor::draw(sf::RenderWindow* window)
{
	window->draw(*m_sprites[static_cast<int>(m_state)]);
}

void Cursor::setCursorState(CursorState state)
{
	m_state = state;
}
