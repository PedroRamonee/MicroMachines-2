#include "game.hpp"

void Game::Render(RenderWindow *window, Player *jogador, Mapa *mapa) {
    mapa->setView(window, jogador);
    jogador->setPos(window);
}

void Game::Run(RenderWindow *window) {
    Mapa mapa;
    Player jogador;
    Event event;

    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            {
                if (event.type == Event::Closed ||
                    Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window->close();
                }
            }
        }

        window->clear();
        Render(window, &jogador, &mapa);
        window->display();
    }
}
