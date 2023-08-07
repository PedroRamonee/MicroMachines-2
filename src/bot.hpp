#ifndef BOT_HPP_
#define BOT_HPP_
#include "entity.hpp"

class Bot : public Entity {
   private:
    Clock clock;
    vector<Vector2f> Waypoints;
    int wayPointCount = 0;
    int ida = 0; //temporario

   public:
    Bot();
    void setPos(RenderWindow* window);
  
};
#endif  // BOT_HPP_