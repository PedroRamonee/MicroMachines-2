#include "entity.hpp"

float Entity::getX() { return posX; }
float Entity::getY() { return posY; }
Sprite Entity::getSprite() { return carro; }
Vector2f Entity::getPosition() { return Vector2f(posX, posY); }