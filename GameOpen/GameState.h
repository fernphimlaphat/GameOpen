//define ifndef
#pragma once
#include "State.h"

class GameState :
    public State

{

private:
    Player* player;

    //Function
    void iniKeybind();
    void iniTexture();
    void iniPlayer();
        
public:

    GameState(sf::RenderWindow* window , std::map<std::string,int>* supportedKey, std::stack<State*>* state);
    virtual ~GameState();

    //Function


    //void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

