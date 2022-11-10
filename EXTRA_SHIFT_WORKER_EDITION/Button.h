#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Corridor;

//handling changing scenes
class Button
{
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	std::string m_locationToGo;
	bool m_isDrawing;
	bool m_isClickable;
	bool m_hasLocationToGo;

	std::function<void(sf::Vector2i mousePos)> m_callback;

public:
	Button(std::string texturePath, std::string locationToGo, sf::Vector2f position, bool isDrawing = true, bool isClickable = true); // for arrows
	Button(std::string locationToGo, sf::Vector2f position, sf::Vector2f size, bool isDrawing = true, bool isClickable = true); //for debug buttons/buttons drawn on the location
	Button(std::function<void(sf::Vector2i mousePos)> func,sf::Vector2f position, sf::Vector2f size, bool isDrawing = true, bool isClickable = true); //for buttons to change states
	~Button();
	void pollEvent(sf::Event event, sf::Vector2i mousePos);
	void update(float dt);
	void draw(sf::RenderWindow* window);

	void setIsDrawing(const bool isDrawing);
	void setIsClickable(const bool isClickable);
	std::string getLocationToGo() const;
	sf::Sprite getSprite() const;
};

