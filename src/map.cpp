#include "map.hpp"

Mapa::Mapa() {
    textura.loadFromFile("assets/mapa.jpeg");
    sprite.setTexture(textura);
    view = setDefault();
}

void Mapa::setView(RenderWindow *window, float X, float Y) {
    view.setCenter(X, Y);

    window->setView(view);
    window->draw(sprite);
}

View setDefault() {
    View start(Vector2f(350.f, 300.f), Vector2f(300.f, 300.f));
    return start;
}