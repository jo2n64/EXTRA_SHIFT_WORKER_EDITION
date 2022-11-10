#pragma once
#include "Location.h"
class BathroomDrawer :
    public Location
{
    std::vector<sf::Sprite*> m_drawers;
    std::vector<ItemButton*> m_upperDrawerItems;
    std::vector<ItemButton*> m_downDrawerItems;

    bool m_upperDrawerOpen;
    bool m_downDrawerOpen;

    bool m_isDownDrawerUnlocked;

    void updateState() override;
    void openUpperDrawer();
    void openLowerDrawer();

    void setupDrawer(std::string texturePath, sf::Vector2f position);
public:
    BathroomDrawer();
    ~BathroomDrawer() override;
    void pollEvent(sf::Event event, sf::Vector2i mousePos) override;
    void render(sf::RenderWindow* window) override;
    void update(float dt, sf::Vector2i mousePos) override;
};

