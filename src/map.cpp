#include "map.hpp"

Mapa::Mapa() {
    textura.loadFromFile("assets/mapa.png");
    sprite.setTexture(textura);
    view = setDefault();
}

void Mapa::setView(RenderWindow *window, float X, float Y) {
    view.setCenter(X, Y);

    window->setView(view);
    window->draw(sprite);
}

View setDefault() {
    View start(sf::Vector2f(350.f, 300.f), sf::Vector2f(300.f, 300.f));
    return start;
}