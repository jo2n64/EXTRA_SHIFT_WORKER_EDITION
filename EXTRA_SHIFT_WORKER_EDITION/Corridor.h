#pragma once
#include "Location.h"
class Corridor :
    public Location
{
    void updateState() override;
public:
    Corridor();
    ~Corridor() override;
    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
    void render(sf::RenderWindow* window) override;
    void update(float dt, sf::Vector2i mousePos) override;
    void openCloset(sf::Vector2i mousePos);
};

