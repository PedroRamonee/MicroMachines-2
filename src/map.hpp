#ifndef MAP_HPP_
#define MAP_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "player.hpp"

using namespace std;
using namespace sf;

class Mapa {
   private:
    Texture textura;
    Sprite sprite;
    View view;
    Vector2f position;
    float X;
    float Y;

   public:
    Mapa();
    void setView(RenderWindow *window, Player *jogador);
};

View setDefault();

#endif  // MAP_HPP_