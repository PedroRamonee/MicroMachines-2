#ifndef MAP_HPP_
#define MAP_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Mapa {
   private:
    Texture textura;
    Sprite sprite;
    View view;
    

   public:
    Mapa();
    void setView(RenderWindow *window, float X, float Y);
};

View setDefault();

#endif  // MAP_HPP_