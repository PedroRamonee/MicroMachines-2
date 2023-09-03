#include "game.hpp"

Game::Game() {
    this->colisionBuffer.loadFromFile("assets/colisao.wav");
    this->outBuffer.loadFromFile("assets/out.wav");
    this->fonte.loadFromFile("assets/font.ttf");
    this->colisionSound.setBuffer(colisionBuffer);
    this->outSound.setBuffer(outBuffer);
    colisionSound.setVolume(40.f);
    outSound.setVolume(40.f);
    control = true;
    colissionDetected = false;
    objectCollide = false;
    dorme = false;
    controlPanel = 1;
    minutos = 0;
    Turns = 0;
    controlCheckPoints = 0;
    volta.setFont(fonte);
    volta.setCharacterSize(20);
    volta.setFillColor(sf::Color::Red);
    tempo.setFont(fonte);
    tempo.setCharacterSize(20);
    tempo.setFillColor(sf::Color::Red);
    clock.restart();
    object.restart();
}

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
    }
    if (objectCollide == true) {
        collideObject(window);
    }
    renderFunctions(window);

    testColission();
    testObstaculos();
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
        colisionSound.play();
    }
}

void Game::testCheckpoint() {
    PlayerHitbox = jogador->getSprite().getGlobalBounds();

    if (PlayerHitbox.intersects(Checkpoints.getHitbox())) {
        cout << "CHECKPOINTZADA LEK" << endl;
        Checkpoints.setCheckpoint();
        controlCheckPoints++;
    }
}

void Game::testObstaculos() {
    PlayerHitbox = jogador->getSprite().getGlobalBounds();

    for (int i = 0; i < 7; i++) {
        if (PlayerHitbox.intersects(personagens.returnPersonagens(i))) {
            objectCollide = true;
        }
    }
}
void Game::collideObject(RenderWindow *window) {
    if (object.getElapsedTime().asMilliseconds() > 10) {
        jogador->collide();
        object.restart();
    }
    window->draw(jogador->getSprite());
    if (jogador->getRepulsion() == 15) {
        objectCollide = false;
    }
}
void Game::countTurns(RenderWindow *window) {
    if (Turns == 0) {
        volta.setString("Voltas: 0/3");
    } else if (Turns == 1) {
        volta.setString("Voltas: 1/3");
    } else if (Turns == 2) {
        volta.setString("Voltas: 2/3");
    } else {
        volta.setString("Voltas: 3/3");
    }
    float x = jogador->getX() + 15;
    float y = jogador->getY() - 135;
    volta.setPosition(x, y);
    window->draw(volta);

    if (controlCheckPoints == 6) {
        Turns++;
        controlCheckPoints = 0;
    }
    if (Turns == 3) {
        cout << "CHEGADA FINAL!!!" << endl;
    }

    if (bot->getCounter() == 3) {
        cout << "BOT GANHOU!!!" << endl;
    }
}

void Game::temporizador(RenderWindow *window) {
    tempo.setString("Tempo - 0.00");

    if ((int(clock.getElapsedTime().asSeconds())) < 60) {
        tempo.setString(
            "Tempo - " + to_string(int(clock.getElapsedTime().asSeconds())) +
            "." +
            to_string(int(clock.getElapsedTime().asMilliseconds() -
                          int(clock.getElapsedTime().asSeconds()) * 1000) /
                      10));
    } else {
        if ((int(clock.getElapsedTime().asSeconds())) % 60 < 10) {
            tempo.setString(
                "Tempo - " +
                to_string(int(clock.getElapsedTime().asSeconds()) / 60) + ":0" +
                to_string(int(clock.getElapsedTime().asSeconds()) % 60));

        } else {
            tempo.setString(
                "Tempo - " +
                to_string(int(clock.getElapsedTime().asSeconds()) / 60) + ":" +
                to_string(int(clock.getElapsedTime().asSeconds()) % 60));
        }
    }
    float x = jogador->getX() + 15;
    float y = jogador->getY() - 115;
    tempo.setPosition(x, y);

    window->draw(tempo);
}
void Game::colissionFunctions(RenderWindow *window) {
    /*
    Realiza as ações necessárias caso os jogadores se interceptem (colisão),
    e desenha as entidades na tela:

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
        -Player->outMap() --> Realiza as medidas para corrigir o
    posicionamento do jogador -Player->getRotate() --> Retorna a angulação
    que o jogador se moveu desde que saiu da tela -Player->setVoltas -->
    Aumenta em 1 unidade o numero de voltas (rotação) que o carro deu
    -Player->setPos() --> Realiza as operações basicas de movimentação do
    jogador -Player->getSprite() --> Retorna o sprite do jogador
    -Bot->setPos() --> Realiza as operações basicas de movimentação do bot

    */
    if (jogador->getOut() == true) {
        if (control) {
            outSound.play();
            control = false;
        }
        if (timer.getElapsedTime().asMilliseconds() > 1) {
            jogador->outMap(Checkpoints.getLastCheck());
            if (jogador->getRotate() == 360) {
                jogador->setVoltas();
            }
            timer.restart();
        }
        window->draw(jogador->getSprite());
    } else {
        control = true;
        jogador->setPos(window);
        testCheckpoint();
        countTurns(window);
        temporizador(window);
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
            if (event.type == Event::Closed) {
                window->close();
            }
        }
        switch (controlPanel) {
            case 0:
                Render(window);
                if (dorme == true) {
                    clock.restart();
                    sleep(seconds(1.5f));
                    clock.restart();
                    dorme = false;
                }
                break;
            case 1:
                window->clear();
                menu->background(window);
                menu->botoes(window, &controlPanel);
                window->display();
                break;
            case 2:
                window->clear();
                menu->credits(window, &controlPanel);
                window->display();
                break;
            case 3:
                window->close();
                break;
            case 4:
                window->clear();
                menu->historia(window, &controlPanel, &dorme);
                window->display();
            default:
                break;
        }
    }
}