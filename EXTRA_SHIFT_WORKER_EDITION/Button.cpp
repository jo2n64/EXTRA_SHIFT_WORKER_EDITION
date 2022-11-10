#include "Button.h"
#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include <functional>

Button::Button(std::string texturePath, std::string locationToGo, sf::Vector2f position, bool isDrawing, bool isClickable)
{
	m_callback = NULL;
	m_hasLocationToGo = true;
	m_isClickable = isClickable;
	m_isDrawing = isDrawing;
	m_locationToGo = locationToGo;
	m_texture = TextureManager::GetTexture(texturePath);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2.f, m_texture.getSize().y / 2.f);
	m_sprite.setPosition(position);
	m_sprite.setScale(0.25f, 0.25f);
}

Button::Button(std::string locationToGo, sf::Vector2f position, sf::Vector2f size, bool isDrawing, bool isClickable)
{
	m_callback = NULL;
	m_hasLocationToGo = true;
	m_isClickable = isClickable;
	m_isDrawing = isDrawing;
	m_locationToGo = locationToGo;
	m_position = position;
	m_texture = TextureManager::GetTexture("../assets/graphics/debug.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(size.x, size.y)));
	m_sprite.setOrigin(size.x / 2.f, size.x / 2.f);
	m_sprite.setPosition(m_position);
}

Button::Button(std::function<void(sf::Vector2i mousePos)> func, sf::Vector2f position, sf::Vector2f size, bool isDrawing, bool isClickable)
{
	m_hasLocationToGo = false;
	m_callback = func;
	m_isClickable = isClickable;
	m_isDrawing = isDrawing;
	m_position = position;
	m_texture = TextureManager::GetTexture("../assets/graphics/debug.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(size.x, size.y)));
	m_sprite.setOrigin(size.x / 2.f, size.x / 2.f);
	m_sprite.setPosition(m_position);

}

Button::~Button()
{
}

void Button::pollEvent(sf::Event event, sf::Vector2i mousePos)
{
	if (m_isClickable) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y) && event.mouseButton.button == sf::Mouse::Left) {
				if (m_hasLocationToGo) {
					Game::getInstance()->setCurrentLocation(m_locationToGo);
					std::cout << "Going to: " << m_locationToGo << std::endl;
				}
				else
				{
					m_callback(mousePos);
				}
			}
		}
	}
}

void Button::update(float dt)
{
}

void Button::draw(sf::RenderWindow* window)
{
	if (m_isDrawing) {
		window->draw(m_sprite);
	}
}

void Button::setIsDrawing(const bool isDrawing)
{
	m_isDrawing = isDrawing;
}

void Button::setIsClickable(const bool isClickable)
{
	m_isClickable = isClickable;
}

std::string Button::getLocationToGo() const
{
	return m_locationToGo;
}

sf::Sprite Button::getSprite() const
{
	return m_sprite;
}

