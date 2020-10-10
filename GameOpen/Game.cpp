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

void Game::iniKey()
{
   //keybord with file
    /*std::ifstream ifs("Config/Keyboard.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKey[key] = key_value;
        }

    }

    ifs.close();

    for (auto i : this->supportedKey)
    {
        std::cout << i.first << " " << i.second << "\n";
    }*/


this->supportedKey.emplace("Escape", sf::Keyboard::Key::Escape);
this->supportedKey.emplace("A", sf::Keyboard::Key::A);
this->supportedKey.emplace("D", sf::Keyboard::Key::D);
this->supportedKey.emplace("W", sf::Keyboard::Key::W);
this->supportedKey.emplace("S", sf::Keyboard::Key::S);
   // this->supportedKey["A"] = sf::Keyboard::Key::A;

}

void Game::iniState()
{
   this->state.push(new MainMenuState(this-> window, &this->supportedKey));
  // this->state.push(new GameState(this-> window, &this->supportedKey));
}

//Constructor/Destuctor

Game::Game()
{
    //แสดงหน้าจอ 
    this->iniWindow();
    this->iniKey();
    this->iniState();

}

Game::~Game()
{
    //clean
    delete this->window;

    while (!this->state.empty())
    {
        delete this->state.top();
        this->state.pop();
    }
}

//Function

void Game::endApp()
{
    printf("End app\n");
}

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

    if (!this->state.empty())
    {
        this->state.top()->update(this->dt);

        if (this->state.top()->getQuit())
        {
            this->state.top()->endState();
            delete this->state.top();
            this->state.pop();
        }
    }
    //quit game
    else
    {
        this->endApp();
        this->window ->close();
    }
    
}

void Game::render()
{
    this->window->clear();
 
    //render item
    if (!this->state.empty())
    {
        this->state.top()->render();
    }

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

