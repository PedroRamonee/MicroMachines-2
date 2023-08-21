#include "game.hpp"

void Game::entityRender(RenderWindow *window) {
    mapa->setView(window, jogador->getX(), jogador->getY());

    if (colissionDetected == true) {
        colissionFunctions(window);
    } else {
        renderFunctions(window);
    }
    testColission();
}

void Game::Render(RenderWindow *window) {
    window->clear(Color::Blue);
    entityRender(window);
    window->display();
}

void Game::testColission() {
    PlayerHitbox = jogador->getSprite().getGlobalBounds();
    BotHitbox = bot->getSprite().getGlobalBounds();

    if (BotHitbox.intersects(PlayerHitbox)) {
        colissionDetected = true;
    }
}

void Game::colissionFunctions(RenderWindow *window) {
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
}

void Game::renderFunctions(RenderWindow *window) {
    if (jogador->getOut() == true) {
        if (timer.getElapsedTime().asMilliseconds() > 3) {
            jogador->outMap();
            if (jogador->getRotate() == 360) {
                jogador->setVoltas();
            }
            timer.restart();
        }
        window->draw(jogador->getSprite());
    } else {
        jogador->setPos(window);
    }

    bot->setPos(window);
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