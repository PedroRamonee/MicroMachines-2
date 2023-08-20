#include "bot.hpp"

Bot::Bot() {
    tex.loadFromFile("assets/Taxi.png");

    carro.setTexture(tex);
    carro.setPosition(790.f, 600.f);
    carro.Transformable::scale(0.2f, 0.2);
    carro.setOrigin(Vector2f(50.f, 50.f));

    posX = carro.getPosition().x;
    posY = carro.getPosition().y;

    initialRotate = carro.getRotation();
    clock.restart();

    Vector2f defaultType;

    for (int i = 0; i < 6; i++) {
        switch (i) {
            case 0:
                defaultType.x = carro.getPosition().x;
                defaultType.y = carro.getPosition().y;
                break;
            case 1:
                defaultType.x = 627;
                defaultType.y = 514;
                break;
            case 2:
                defaultType.x = 80;
                defaultType.y = 514;
                break;
            case 3:
                defaultType.x = 80;
                defaultType.y = 384;
                break;
            case 4:
                defaultType.x = 320;
                defaultType.y = 384;
                break;
            case 5:
                defaultType.x = 482;
                defaultType.y = 289;
                break;
            default:
                break;
        }

        Waypoints.push_back(defaultType);
    }
}

void Bot::setPos(RenderWindow* window) {
    if (clock.getElapsedTime().asMilliseconds() > 2) {
        if (wayPointCount <= 5 && ida == 0) {
            if (carro.getPosition().x != Waypoints[wayPointCount].x &&
                carro.getPosition().y == Waypoints[wayPointCount].y) {
                if (carro.getPosition().x > Waypoints[wayPointCount].x) {
                    posX -= 1;
                    carro.setRotation(initialRotate - 90.f);
                } else {
                    posX += 1;
                    carro.setRotation(initialRotate + 90.f);
                }
            }

            else if (carro.getPosition().y != Waypoints[wayPointCount].y &&
                     carro.getPosition().x == Waypoints[wayPointCount].x) {
                if (carro.getPosition().y > Waypoints[wayPointCount].y) {
                    posY -= 1;
                    carro.setRotation(initialRotate);
                } else {
                    posY += 1;
                    carro.setRotation(initialRotate + 180.f);
                }

            } else if (carro.getPosition().x != Waypoints[wayPointCount].x &&
                       carro.getPosition().y != Waypoints[wayPointCount].y) {
                if (carro.getPosition().x > Waypoints[wayPointCount].x &&
                    carro.getPosition().y > Waypoints[wayPointCount].y) {
                    posX -= 0.5;
                    posY -= 0.5;

                    carro.setRotation(initialRotate - 45.f);
                } else if (carro.getPosition().x < Waypoints[wayPointCount].x &&
                           carro.getPosition().y < Waypoints[wayPointCount].y) {
                    posX += 0.5;
                    posY += 0.5;

                    carro.setRotation(initialRotate + 45.f);
                } else if (carro.getPosition().x > Waypoints[wayPointCount].x &&
                           carro.getPosition().y < Waypoints[wayPointCount].y) {
                    posX -= 0.5;
                    posY += 0.5;

                    carro.setRotation(initialRotate + 135.f);
                } else if (carro.getPosition().x < Waypoints[wayPointCount].x &&
                           carro.getPosition().y > Waypoints[wayPointCount].y) {
                    posX += 0.5;
                    posY -= 0.5;

                    carro.setRotation(initialRotate - 135.f);
                }
            }

            if (carro.getPosition() == Waypoints[wayPointCount]) {
                if (wayPointCount == 5) {
                    ida = 1;
                    wayPointCount == 4;
                } else {
                    wayPointCount++;
                }
            }
        } else {
            if (carro.getPosition().x != Waypoints[wayPointCount].x &&
                carro.getPosition().y == Waypoints[wayPointCount].y) {
                if (carro.getPosition().x > Waypoints[wayPointCount].x) {
                    posX -= 1;
                    carro.setRotation(initialRotate - 90.f);
                } else {
                    posX += 1;
                    carro.setRotation(initialRotate + 90.f);
                }
            }

            else if (carro.getPosition().y != Waypoints[wayPointCount].y &&
                     carro.getPosition().x == Waypoints[wayPointCount].x) {
                if (carro.getPosition().y > Waypoints[wayPointCount].y) {
                    posY -= 1;
                    carro.setRotation(initialRotate);
                } else {
                    posY += 1;
                    carro.setRotation(initialRotate + 180.f);
                }

            } else if (carro.getPosition().x != Waypoints[wayPointCount].x &&
                       carro.getPosition().y != Waypoints[wayPointCount].y) {
                if (carro.getPosition().x > Waypoints[wayPointCount].x &&
                    carro.getPosition().y > Waypoints[wayPointCount].y) {
                    posX -= 0.5;
                    posY -= 0.5;

                    carro.setRotation(initialRotate - 135.f);
                } else if (carro.getPosition().x < Waypoints[wayPointCount].x &&
                           carro.getPosition().y < Waypoints[wayPointCount].y) {
                    posX += 0.5;
                    posY += 0.5;

                    carro.setRotation(initialRotate + 135.f);
                } else if (carro.getPosition().x > Waypoints[wayPointCount].x &&
                           carro.getPosition().y < Waypoints[wayPointCount].y) {
                    posX -= 0.5;
                    posY += 0.5;

                    carro.setRotation(initialRotate + 45.f);
                } else if (carro.getPosition().x < Waypoints[wayPointCount].x &&
                           carro.getPosition().y > Waypoints[wayPointCount].y) {
                    posX += 0.5;
                    posY -= 0.5;

                    carro.setRotation(initialRotate - 45.f);
                }
            }

            if (carro.getPosition() == Waypoints[wayPointCount]) {
                if (wayPointCount == 0) {
                    ida = 0;
                    wayPointCount == 1;
                } else {
                    wayPointCount--;
                }
            }
        }

        clock.restart();
    }

    //  cout << posX << "," << posY << endl;
    
    carro.setPosition(posX, posY);
    window->draw(carro);
}

float Bot::getRepulsion() { return repulsion; }

void Bot::collide(int typeRotate) {
    switch (typeRotate) {
        case 0:
            posY -= repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 1:
            posX += repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 2:
            posX -= repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 3:
            posY += repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 4:
            posY -= (repulsion / 2);
            posX += (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 5:
            posY -= (repulsion / 2);
            posX -= (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 6:
            posY += (repulsion / 2);
            posX += (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 7:
            posY += (repulsion / 2);
            posX -= (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        default:
            break;
    }

    carro.setPosition(posX, posY);
}