#include "game.hpp"

void Game::entityRender(RenderWindow *window) {
    mapa->setView(window, jogador->getX(), jogador->getY());

    if (jogador->getOut() == true) {
        jogador->outMap(window);
        if (jogador->getRotate() == 360) {
            jogador->setVoltas();
        }
        sleep(seconds(0.003f));
    } else {
        jogador->setPos(window);
    }
    bot->setPos(window);
}

void Game::Render(RenderWindow *window) {
    window->clear(Color::Blue);
    entityRender(window);
    window->display();
}

void Game::Run(RenderWindow *window) {
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            {
                if (event.type == Event::Closed ||
                    Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window->close();
                }
            }
        }

        Render(window);
    }
}
