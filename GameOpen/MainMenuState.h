#pragma once

#include "GameState.h"
#include "Button.h"


class MainMenuState :
    public State
{
private:
    //verible
    sf::RectangleShape background;
    sf::Font font;

    Button* gamestate_btn;

    //Function
    void iniFont();
    void iniKeybind();

public:

    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKey);
    virtual ~MainMenuState();

    //Function


    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

