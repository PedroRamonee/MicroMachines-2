#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "entity.hpp"

class Player : public Entity {
   private:
    Vector2f initialPos;
    bool out;
    int voltas;
    int rotate;
    float actualRotate;
    Vector2f velocidade;
    float repulsion;
    int typeRotate;

   public:
    Player();
    void setPos(RenderWindow *window);
    void outMap();
    int getRotate();
    bool getOut();
    void setVoltas();
    Vector2f getSpeed();
    void collide();
    float getRepulsion();
    float getTypeRotate();
};

#endif  // PLAYER_HPP_