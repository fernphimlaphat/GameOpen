#pragma once
#include "Entity.h"



class Player :
    public Entity
{
private:

    //Variable


    //ini function
    void iniVariable();
    void iniComponent();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    //Function
};

