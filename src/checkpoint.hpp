#ifndef CHECKPOINT_HPP_
#define CHECKPOINT_HPP_

#include "map.hpp"

class Checkpoint {
   private:
    FloatRect HitboxCheckpoint;
    vector<Vector2f> CheckpointsPosition;
    int CurrentCheckpoint;


   public:
    Checkpoint();
    void setCheckpoint();
    FloatRect getHitbox();
    Vector2f getLastCheck();
};

#endif  // CHECKPOINT_HPP_