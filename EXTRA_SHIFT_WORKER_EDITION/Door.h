#pragma once
#include "InteractablePlace.h"
class Door :
    public InteractablePlace
{
private:
public:
    Door();
    ~Door();
	void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
    void draw(sf::RenderWindow* window) override;
};

