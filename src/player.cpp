#include "player.hpp"

Player::Player() {
    tex.loadFromFile("assets/Audi.png");

    carro.setTexture(tex);
    carro.setPosition(717.f, 584.f);
    carro.Transformable::scale(0.2f, 0.2);
    carro.setOrigin(Vector2f(50.f, 50.f));

    posX = carro.getPosition().x;
    posY = carro.getPosition().y;

    initialRotate = carro.getRotation();
    initialPos = carro.getPosition();
    actualRotate = carro.getRotation();
}

void Player::setPos(RenderWindow *window) {
    if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        posX += 0.25;
        carro.setRotation(initialRotate + 90.f);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        posX -= 0.25;
        carro.setRotation(initialRotate - 90.f);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        posY -= 0.25;
        carro.setRotation(initialRotate);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        posY += 0.25;
        carro.setRotation(initialRotate + 180.f);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        carro.setRotation(initialRotate + 45.f);
        posX -= 0.05;
        posY += 0.05;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        carro.setRotation(initialRotate - 45.f);
        posX += 0.05;
        posY += 0.05;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        carro.setRotation(initialRotate + 135.f);
        posX -= 0.05;
        posY -= 0.05;
    }

    if (Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        carro.setRotation(initialRotate - 135.f);
        posX += 0.05;
        posY -= 0.05;
    }

    actualRotate = carro.getRotation();

    cout << posX << "," << posY << endl;

    if (posX < 0 || posX > 1200 || posY < 0 || posY > 1200) {
        out = true;
    } else {
        carro.setPosition(posX, posY);
        window->draw(carro);
    }
}

float Player::getX() { return posX; }
float Player::getY() { return posY; }
int Player::getRotate() { return rotate; }
bool Player::getOut() { return out; }
void Player::setVoltas() { voltas++; }

void Player::outMap(RenderWindow *window) {
    carro.setRotation(actualRotate + rotate);
    window->draw(carro);

    rotate++;

    if (rotate > 360) {
        rotate = 0;
    }
    if (voltas == 3) {
        out = false;
        posX = initialPos.x;
        posY = initialPos.y;
        voltas = 0;
    }
}