#include "player.hpp"

Player::Player() {
    tex.loadFromFile("assets/Audi.png");

    carro.setTexture(tex);
    carro.setPosition(1700.f, 764.f);
    carro.Transformable::scale(0.2f, 0.2);

    posX = carro.getPosition().x;
    posY = carro.getPosition().y;

    initialRotate = carro.getRotation();
}

void Player::setPos(RenderWindow *window) {
    if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        posX += 0.5;
        carro.setRotation(initialRotate + 90.f);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        posX -= 0.5;
        carro.setRotation(initialRotate - 90.f);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        posY -= 0.5;
        carro.setRotation(initialRotate);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        posY += 0.5;
        carro.setRotation(initialRotate + 180.f);
        
    }
    if(Keyboard::isKeyPressed(sf::Keyboard::Right) && Keyboard::isKeyPressed(sf::Keyboard::Up)){
        carro.setRotation(initialRotate + 45.f);
    }
     if(Keyboard::isKeyPressed(sf::Keyboard::Left) && Keyboard::isKeyPressed(sf::Keyboard::Up)){
        carro.setRotation(initialRotate - 45.f);
    }
     if(Keyboard::isKeyPressed(sf::Keyboard::Right) && Keyboard::isKeyPressed(sf::Keyboard::Down)){
        carro.setRotation(initialRotate + 135.f);
    }
     if(Keyboard::isKeyPressed(sf::Keyboard::Left) && Keyboard::isKeyPressed(sf::Keyboard::Down)){
        carro.setRotation(initialRotate - 135.f);
    }
    

    cout << posX << "," << posY << endl;

    carro.setPosition(posX, posY);
    window->draw(carro);
}

float Player::getX() { return posX; }
float Player::getY() { return posY; }