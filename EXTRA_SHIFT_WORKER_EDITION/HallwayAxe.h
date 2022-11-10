#pragma once
#include "Location.h"
class HallwayAxe :
    public Location
{
    void updateState() override;
public:
    HallwayAxe();
    ~HallwayAxe() override;
    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
};

