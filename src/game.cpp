#include "game.hpp"

void Game::entityRender(RenderWindow *window) {
    /*
    Renderização das entidades do jogo:

        - Mapa->setView() --> Função que posiciona a view da janela e desenha o
    mapa na tela
        - Game->colissionFunctions() --> Função que chama as funções de colisão
    do jogo (caso alguma colisão aconteça)
        - Game->renderFunctions() --> Função que chama as funções normais de
    renderização do jogo (caso não esteja acontecendo alguma colisão)
        - Game->testColission() --> Função que testa se há alguma colisão entre
    os jogadores no jogo


    */
    mapa->setView(window, jogador->getX(), jogador->getY());

    if (colissionDetected == true) {
        colissionFunctions(window);
    } else {
        renderFunctions(window);
    }
    testColission();
}

void Game::Render(RenderWindow *window) {
    /*
    Tratamento da tela e função intermediária na renderização das entidades:

        - Game->entityRender() --> Função que chama as funções que renderizão as
    entidades do jogo

    */

    window->clear(Color::Blue);
    entityRender(window);
    window->display();
}

void Game::testColission() {
    /*
    Teste de colisão são entre as entidades do jogo:

        PlayerHitbox --> Hitbox do jogador
        BotHitbox --> Hitbox do bot

        Caso as hitbox se interceptem a colisão se torna verdadeira e
    desencadeia uma serie de funções que simulam a colisão dos jogadores
    */

    PlayerHitbox = jogador->getSprite().getGlobalBounds();
    BotHitbox = bot->getSprite().getGlobalBounds();

    if (BotHitbox.intersects(PlayerHitbox)) {
        colissionDetected = true;
    }
}

void Game::testCheckpoint() {
    PlayerHitbox = jogador->getSprite().getGlobalBounds();

    if (PlayerHitbox.intersects(Checkpoints.getHitbox())) {
        cout << "CHECKPOINTZADA LEK" << endl;
        Checkpoints.setCheckpoint();
    }
}

void Game::colissionFunctions(RenderWindow *window) {
    /*
    Realiza as ações necessárias caso os jogadores se interceptem (colisão), e
    desenha as entidades na tela:

        -Player->collide() --> Função que simula a colisão do jogador
        -Bot->collide() --> Função que simula a colisão do bot

        Assim que ambas colisões forem totalmente realizadas, desencadeia as
    funções de renderização normal do game

    */
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
    /*
    Realiza as renderizações padrões do jogo, contudo, caso o jogador se
    posicione para fora do mapa desecandeia as funções para corrigir o
    posicionamento:

        -Player->getOut() --> Retorna se o jogador está ou não fora da tela
        -Player->outMap() --> Realiza as medidas para corrigir o posicionamento
    do jogador -Player->getRotate() --> Retorna a angulação que o jogador se
    moveu desde que saiu da tela -Player->setVoltas --> Aumenta em 1 unidade o
    numero de voltas (rotação) que o carro deu -Player->setPos() --> Realiza as
    operações basicas de movimentação do jogador -Player->getSprite() -->
    Retorna o sprite do jogador -Bot->setPos() --> Realiza as operações basicas
    de movimentação do bot

    */
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
        testCheckpoint();
        window->draw(Checkpoints.getQuadrado());
    }

    bot->setPos(window);
}

void Game::Run(RenderWindow *window) {
    /*
    Loop principal do jogo, Função de tratamento de tela é chamada e
    (futuramente) os menus são chamados:

        -Game->Render() --> Realiza o tratamento da tela e chama as outras
    funções necessárias


    */
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