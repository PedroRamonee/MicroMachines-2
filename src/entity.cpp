#include "entity.hpp"

float Entity::getX() { return posX; }         // retorna a posição X
float Entity::getY() { return posY; }         // retorna a posição Y
Sprite Entity::getSprite() { return carro; }  // retorna o sprite
Vector2f Entity::getPosition() {
    return Vector2f(posX, posY);
}  // retorna a posição X e Y em formato de coordenada(vector2f)