#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "entity.hpp"

class Player : public Entity {
   private:
    Vector2f initialPos;

   public:
    Player();
    void setPos(RenderWindow *window);
    float getX();
    float getY();
};

#endif  // PLAYER_HPP_