#pragma once
#include "Location.h"
class Hallway :
    public Location
{
    void updateState() override;
public:
    Hallway();
    ~Hallway();
    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
    void update(float dt, sf::Vector2i mousePos) override;
};

