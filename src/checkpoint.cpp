#include "checkpoint.hpp"

Checkpoint ::Checkpoint() {
    /*
   Construtor da classe Checkpoint:

       - Checkpoints são definidos
       - Hitbox é inicidalizada
   */

    Vector2f defaultType;

    for (int i = 0; i < 6; i++) {
        switch (i) {
            case 0:
                defaultType.x = 40;
                defaultType.y = 400;
                break;
            case 1:
                defaultType.x = 475;
                defaultType.y = 223;
                break;
            case 2:
                defaultType.x = 1065;
                defaultType.y = 319;
                break;
            case 3:
                defaultType.x = 1065;
                defaultType.y = 819;
                break;
            case 4:
                defaultType.x = 100;
                defaultType.y = 819;
                break;
            case 5:
                defaultType.x = 685;
                defaultType.y = 589;
                break;
            default:
                break;
        }

        CheckpointsPosition.push_back(defaultType);
    }

    CurrentCheckpoint = 0;

    HitboxCheckpoint.height = 100.f;
    HitboxCheckpoint.width = 100.f;
    HitboxCheckpoint.top = CheckpointsPosition[CurrentCheckpoint].y;
    HitboxCheckpoint.left = CheckpointsPosition[CurrentCheckpoint].x;
}

FloatRect Checkpoint::getHitbox() {
    return HitboxCheckpoint;
}  // retorna a hitbox

void Checkpoint::setCheckpoint() {
    /*
     Realiza a troca de checkpoints
  */

    if (CurrentCheckpoint == 5) {
        CurrentCheckpoint = 0;
    } else {
        CurrentCheckpoint++;
    }
    HitboxCheckpoint.top = CheckpointsPosition[CurrentCheckpoint].y;
    HitboxCheckpoint.left = CheckpointsPosition[CurrentCheckpoint].x;
}

Vector2f Checkpoint::getLastCheck() {
    if (CurrentCheckpoint > 0) {
        return CheckpointsPosition[CurrentCheckpoint - 1];
    } else {
        return CheckpointsPosition[5];
    }
}