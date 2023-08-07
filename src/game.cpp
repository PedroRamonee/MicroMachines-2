#include "game.hpp"

void Game::Render(RenderWindow *window, Player *jogador, Mapa *mapa, Bot *bot) {
    mapa->setView(window, jogador->getX(), jogador->getY());
    jogador->setPos(window);
    bot->setPos(window);
}

void Game::Run(RenderWindow *window) {
    Mapa *mapa = new Mapa();
    Player *jogador = new Player();
    Event event;
    Bot *bot = new Bot();

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
        Render(window, jogador, mapa, bot);
        window->display();
    }
}
