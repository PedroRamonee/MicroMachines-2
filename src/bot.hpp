#ifndef BOT_HPP_
#define BOT_HPP_
#include "entity.hpp"

class Bot : public Entity {
   private:
    Clock clock;
    vector<Vector2f> Waypoints;
    int wayPointCount;
    int ida;  // temporario
    float repulsion;

   public:
    Bot();
    void setPos(RenderWindow* window);
    void collide(int typeRotate);
    float getRepulsion();
};
#endif  // BOT_HPP_