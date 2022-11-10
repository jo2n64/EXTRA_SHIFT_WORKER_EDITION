#pragma once
#include "InteractablePlace.h"

class EyeDrops :
    public InteractablePlace
{

public:
    EyeDrops(sf::Vector2f position);
    ~EyeDrops();

    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
    void draw(sf::RenderWindow* window) override;
};

