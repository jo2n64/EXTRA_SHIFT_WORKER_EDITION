#pragma once
#include "Location.h"
class KitchenOven :
    public Location
{
    void updateState() override;
public:
    KitchenOven();
    ~KitchenOven() override;
    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
};

