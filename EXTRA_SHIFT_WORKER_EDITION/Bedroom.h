#pragma once
#include "Location.h"
class Bedroom :
    public Location
{
    void updateState() override;
public:
    Bedroom();
    ~Bedroom();
    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
};

