#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "entity.hpp"

class Player : public Entity {
   private:
    Vector2f initialPos;
    bool out = false;
    int voltas = 0, rotate = 0;
    float actualRotate;
    Vector2f velocidade;
    float repulsion = 1;
    int typeRotate = 0;

   public:
    Player();
    void setPos(RenderWindow *window);
    void outMap(RenderWindow *window);
    int getRotate();
    bool getOut();
    void setVoltas();
    Vector2f getSpeed();
    void collide();
    float getRepulsion();
    float getTypeRotate();
};

#endif  // PLAYER_HPP_