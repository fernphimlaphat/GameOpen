#include "Game.h"

//Static function

//Initializer function


void Game::iniWindow()
{
    //แสดงขนาดหน้าจอ 

    std::ifstream ifs("Config/window.ini");
    
    std::string title = "None";
    sf::VideoMode window_bounds(800,600);
    unsigned framerate_limit = 120;
    bool veriable_sync_enabled = false;

    if(ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> veriable_sync_enabled;
    }
    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(veriable_sync_enabled);
}

//Constructor/Destuctor


Game::Game()
{
    //แสดงหน้าจอ 
    this->iniWindow();
}

Game::~Game()
{
    //clean
    delete this->window;
}

//function

void Game::updateDT()
{
    //update and render one frame
    this->dt = this->dtClock.restart().asSeconds();
  
}

void Game::updateSFMLEvent()
{

    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }

   
}

void Game::update()
{
    this->updateSFMLEvent();
    
}

void Game::render()
{
    this->window->clear();
 
    //render item

    this->window->display();
}

void Game::run()
{
      while (this->window->isOpen())
    {
          this->updateDT();
          this->update();
          this->render();
    }

}

