#include "player.hpp"

Player::Player() {
    tex.loadFromFile("assets/Audi.png");

    carro.setTexture(tex);
    carro.setPosition(1672.f, 764.f);
    carro.Transformable::scale(0.2f, 0.2);

    posX = carro.getPosition().x;
    posY = carro.getPosition().y;

    clock.restart();

    Vector2f defaultType;

    for (int i = 0; i < 6; i++) {
        switch (i) {
            case 0:
                defaultType.x = 1672;
                defaultType.y = 764;
                break;
            case 1:
                defaultType.x = 1672;
                defaultType.y = 566;
                break;
            case 2:
                defaultType.x = 1504;
                defaultType.y = 429;
                break;
            case 3:
                defaultType.x = 1239;
                defaultType.y = 429;
                break;
            case 4:
                defaultType.x = 1141;
                defaultType.y = 328;
                break;
            case 5:
                defaultType.x = 751;
                defaultType.y = 328;
                break;
            default:
                break;
        }

        Waypoints.push_back(defaultType);
    }

    initialRotate = carro.getRotation();
}

void Player::setPos(RenderWindow *window) {
    /*
    if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        posX += 0.1;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        posX -= 0.1;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        posY -= 0.1;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        posY += 0.1;
    }
    */
    cout << posX << "," << posY << endl;
    if (clock.getElapsedTime().asSeconds() > 0.01) {
        if (wayPointCount <= 5 && ida == 0) {
            if (carro.getPosition().x > Waypoints[wayPointCount].x &&
                carro.getPosition().y == Waypoints[wayPointCount].y) {
                posX -= 1;

                carro.setRotation(initialRotate - 90.f);

            } else if (carro.getPosition().y > Waypoints[wayPointCount].y &&
                       carro.getPosition().x == Waypoints[wayPointCount].x) {
                posY -= 1;
                carro.setRotation(initialRotate);
            } else if (carro.getPosition().x > Waypoints[wayPointCount].x &&
                       carro.getPosition().y > Waypoints[wayPointCount].y) {
                posX -= 1;
                posY -= 1;

                carro.setRotation(initialRotate - 45.f);
            }

            if (carro.getPosition() == Waypoints[wayPointCount]) {
                if (wayPointCount == 5) {
                    ida = 1;
                    wayPointCount == 4;
                } else {
                    wayPointCount++;
                }
            }
        }

        else {
            if (carro.getPosition().x < Waypoints[wayPointCount].x &&
                carro.getPosition().y == Waypoints[wayPointCount].y) {
                posX += 1;
                carro.setRotation(initialRotate + 90.f);
            } else if (carro.getPosition().y < Waypoints[wayPointCount].y &&
                       carro.getPosition().x == Waypoints[wayPointCount].x) {
                posY += 1;
                carro.setRotation(initialRotate + 180.f);
            } else if (carro.getPosition().x < Waypoints[wayPointCount].x &&
                       carro.getPosition().y < Waypoints[wayPointCount].y) {
                posX += 1;
                posY += 1;

                carro.setRotation(initialRotate + 120.f);
            }

            if (carro.getPosition() == Waypoints[wayPointCount]) {
                if (wayPointCount == 0) {
                    ida = 0;
                    wayPointCount == 0;
                } else {
                    wayPointCount--;
                }
            }
        }

        clock.restart();
    }

    carro.setPosition(posX, posY);
    window->draw(carro);
}

float Player::getX() { return posX; }
float Player::getY() { return posY; }