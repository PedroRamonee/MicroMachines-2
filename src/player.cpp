#include "player.hpp"

Player::Player() {
    tex.loadFromFile("assets/Audi.png");

    carro.setTexture(tex);
    carro.setPosition(690.f, 600.f);
    carro.Transformable::scale(0.2f, 0.2);
    carro.setOrigin(Vector2f(50.f, 50.f));

    posX = carro.getPosition().x;
    posY = carro.getPosition().y;

    initialRotate = carro.getRotation();
    initialPos = carro.getPosition();
    actualRotate = carro.getRotation();

    velocidade.x = 0;
    velocidade.y = 0;

    typeRotate = 0;
    repulsion = 1;
    voltas = 0;
    rotate = 0;
    out = false;
}

void Player::setPos(RenderWindow *window) {
    velocidade.x = 0;
    velocidade.y = 0;
    if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocidade.x = 0.20;
        velocidade.y = 0;
        carro.setRotation(initialRotate + 90.f);
        typeRotate = 1;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocidade.x = -0.20;
        velocidade.y = 0;
        carro.setRotation(initialRotate - 90.f);
        typeRotate = 2;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocidade.y = -0.20;
        velocidade.x = 0;
        carro.setRotation(initialRotate);
        typeRotate = 0;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocidade.y = 0.20;
        velocidade.x = 0;
        carro.setRotation(initialRotate + 180.f);
        typeRotate = 3;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        carro.setRotation(initialRotate + 45.f);
        velocidade.x = 0.14;
        velocidade.y = -0.14;
        typeRotate = 4;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        carro.setRotation(initialRotate - 45.f);
        velocidade.x = -0.14;
        velocidade.y = -0.14;
        typeRotate = 5;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        carro.setRotation(initialRotate + 135.f);
        velocidade.x = 0.14;
        velocidade.y = 0.14;
        typeRotate = 6;
    }

    if (Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        carro.setRotation(initialRotate - 135.f);
        velocidade.x = -0.14;
        velocidade.y = 0.14;
        typeRotate = 7;
    }

    actualRotate = carro.getRotation();

    posX += velocidade.x;
    posY += velocidade.y;

    // cout << posX << "," << posY << endl;

    if (posX + carro.getGlobalBounds().width < 0 ||
        posX - carro.getGlobalBounds().width > 1200 ||
        posY + carro.getGlobalBounds().height < 0 ||
        posY - carro.getGlobalBounds().height > 1200) {
        out = true;
    } else {
        carro.setPosition(posX, posY);
        window->draw(carro);
    }
}

int Player::getRotate() { return rotate; }
bool Player::getOut() { return out; }
void Player::setVoltas() { voltas++; }
Vector2f Player::getSpeed() { return velocidade; }
float Player::getRepulsion() { return repulsion; }
float Player::getTypeRotate() { return typeRotate; }

void Player::outMap() {
    carro.setRotation(actualRotate + rotate);

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

void Player::collide() {
    switch (typeRotate) {
        case 0:
            posY += repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 1:
            posX -= repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 2:
            posX += repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 3:
            posY -= repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 4:
            posY += (repulsion / 2);
            posX -= (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 5:
            posY += (repulsion / 2);
            posX += (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 6:
            posY -= (repulsion / 2);
            posX -= (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 7:
            posY -= (repulsion / 2);
            posX += (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        default:
            break;
    }

    cout << repulsion << endl;

    cout << "PosX ->" << posX << "\nPosY ->" << posY << endl;

    carro.setPosition(posX, posY);
}