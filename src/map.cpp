#include "map.hpp"

Mapa::Mapa() {
    /*
    Construtor da classe Mapa:

        - Textura é carregada
        - Sprite é definido
        - View é inicializada
    */
    textura.loadFromFile("assets/mapa.jpeg");
    sprite.setTexture(textura);
    view = setDefault();
}

void Mapa::setView(RenderWindow *window, float X, float Y) {
    /*
    Centralização da visão e renderização do mapa:

        - Centraliza a visão da janela no Player
        - Define a view da janela
        - Desenha o mapa
    */
    view.setCenter(X, Y);

    window->setView(view);
    window->draw(sprite);
}

View setDefault() {
    /*
    Inicializa uma view normal e retorna ela
    */
    View start(Vector2f(350.f, 300.f), Vector2f(300.f, 300.f));
    return start;
}