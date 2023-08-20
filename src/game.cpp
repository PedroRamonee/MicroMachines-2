#include "game.hpp"

void Game::entityRender(RenderWindow *window) {
    mapa->setView(window, jogador->getX(), jogador->getY());

    if (colissionDetected == true) {
        if (timer.getElapsedTime().asMilliseconds() > 10) {
            jogador->collide();
            bot->collide(jogador->getTypeRotate());
            timer.restart();
        }
        window->draw(jogador->getSprite());
        window->draw(bot->getSprite());

        if (jogador->getRepulsion() == 15 && bot->getRepulsion() == 15) {
            colissionDetected = false;
        }
    } else {
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
    testColission();
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

void Game::testColission() {
    PlayerBounds = jogador->getSprite().getGlobalBounds();
    BotBounds = bot->getSprite().getGlobalBounds();

    nextPosition = PlayerBounds;
    nextPosition.left += jogador->getSpeed().x;
    nextPosition.top += jogador->getSpeed().y;

    if (BotBounds.intersects(nextPosition)) {
        colissionDetected = true;
    }
}