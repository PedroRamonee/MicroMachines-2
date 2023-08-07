#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Player {
   private:
    // teste
    Texture tex;
    Sprite carro;
    float posX;
    float posY;
    Clock clock;
    vector <Vector2f> Waypoints;
    int wayPointCount = 0;
    int ida = 0;
    float initialRotate;
    

   public:
    Player();
    void setPos(RenderWindow *window);
    float getX();
    float getY();
};

#endif  // PLAYER_HPP_