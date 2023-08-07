#ifndef ENTITY_HPP_
#define ENTITY_HPP_
#include "map.hpp"

class Entity {
   protected:

    Texture tex;
    Sprite carro;
    float posX;
    float posY;
    float initialRotate;
};
#endif  // ENTITY_HPP_