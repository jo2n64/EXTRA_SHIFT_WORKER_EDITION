#pragma once
#include "InteractablePlace.h"
class Meds :
    public InteractablePlace
{
private:
public:
    Meds(sf::Vector2f position);
    ~Meds();

    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
    void draw(sf::RenderWindow* window) override;
};

