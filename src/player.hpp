#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "entity.hpp"

class Player : public Entity {
   private:
    Vector2f initialPos;
    bool out = false;
    int voltas = 0, rotate = 0;
    float actualRotate;

   public:
    Player();
    void setPos(RenderWindow *window);
    void outMap(RenderWindow *window);
    int getRotate();
    float getX();
    float getY();
    bool getOut();
    void setVoltas();
};

#endif  // PLAYER_HPP_