#include "map.hpp"

Mapa::Mapa() {
    textura.loadFromFile("assets/mapa.png");
    sprite.setTexture(textura);
    view = setDefault();
    position = view.getCenter();
    X = position.x;
    Y = position.y;
}

void Mapa::setView(RenderWindow *window, Player *jogador) {
    X = jogador->getX();
    Y = jogador->getY();
    view.setCenter(X, Y);

    window->setView(view);
    window->draw(sprite);
}

View setDefault() {
    View start(sf::Vector2f(350.f, 300.f), sf::Vector2f(300.f, 300.f));
    return start;
}