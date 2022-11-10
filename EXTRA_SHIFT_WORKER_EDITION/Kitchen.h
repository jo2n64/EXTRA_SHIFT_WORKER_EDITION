#pragma once
#include "Location.h"
class Kitchen :
    public Location
{
    void updateState() override;
public:
    Kitchen();
    ~Kitchen();
    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
};

