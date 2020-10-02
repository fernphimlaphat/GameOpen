//define ifndef
#pragma once
#include "State.h"

class GameState :
    public State

{

private:
    Entity player;


    //Function
    void iniKeybind();
        
public:

    GameState(sf::RenderWindow* window , std::map<std::string,int>* supportedKey);
    virtual ~GameState();

    //Function


    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

