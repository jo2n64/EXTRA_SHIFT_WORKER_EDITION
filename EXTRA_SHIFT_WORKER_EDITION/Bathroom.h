#pragma once
#include "Location.h"
class Bathroom :
    public Location
{
    void updateState() override;
public:
    Bathroom();
    ~Bathroom() override;
    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
};

