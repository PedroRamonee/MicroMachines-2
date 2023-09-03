#include "menu.hpp"

Menu::Menu() {
    // Construtor

    this->musicasFinal[0].openFromFile("assets/GOODENDING/music.wav");
    this->musicasFinal[1].openFromFile("assets/GOODENDING/yay.wav");
    this->musicasFinal[2].openFromFile("assets/BADENDING/musica.wav");
    this->musicasFinal[3].openFromFile("assets/BADENDING/jumpsacre.wav");

    this->mainmenu[0].loadFromFile("assets/1.png");
    this->mainmenu[1].loadFromFile("assets/2.png");
    this->mainmenu[2].loadFromFile("assets/3.png");
    this->mainmenu[3].loadFromFile("assets/4.png");
    this->mainmenu[4].loadFromFile("assets/5.png");
    this->mainmenu[5].loadFromFile("assets/6.png");
    this->mainmenu[6].loadFromFile("assets/7.png");
    this->mainmenu[7].loadFromFile("assets/8.png");
    this->mainmenu[8].loadFromFile("assets/9.png");
    this->mainmenu[9].loadFromFile("assets/10.png");

    this->menutema.openFromFile("assets/tema.wav");
    menutema.play();

    this->temahist.openFromFile("assets/temadahist.wav");

    this->count = 0;

    this->counthist = 0;

    this->botaocount = 0;

    this->historiaimg[0].loadFromFile("assets/historia1.png");
    this->historiaimg[1].loadFromFile("assets/historia2.png");
    this->historiaimg[2].loadFromFile("assets/historia3.png");
    this->historiaimg[3].loadFromFile("assets/historia4.png");
    this->historiaimg[4].loadFromFile("assets/historia5.png");
    this->historiaimg[5].loadFromFile("assets/historia6.png");
    this->historiaimg[6].loadFromFile("assets/historia7.png");
    this->historiaimg[7].loadFromFile("assets/historia8.png");
    this->historiaimg[8].loadFromFile("assets/historia9.png");
    this->historiaimg[9].loadFromFile("assets/historia10.png");

    this->creditos.loadFromFile("assets/11.png");

    this->tema.openFromFile("assets/tema2.wav");
    tema.setLoop(true);
    tema.setVolume(40.f);

    this->historiaFinalimg[0].loadFromFile("assets/GOODENDING/0.png");
    this->historiaFinalimg[1].loadFromFile("assets/GOODENDING/1.png");
    this->historiaFinalimg[2].loadFromFile("assets/GOODENDING/2.png");
    this->historiaFinalimg[3].loadFromFile("assets/GOODENDING/3.png");
    this->historiaFinalimg[4].loadFromFile("assets/GOODENDING/4.png");
    this->historiaFinalimg[5].loadFromFile("assets/GOODENDING/5.png");
    this->historiaFinalimg[6].loadFromFile("assets/GOODENDING/6.png");
    this->historiaFinalimg[7].loadFromFile("assets/GOODENDING/7.png");
    this->historiaFinalimg[8].loadFromFile("assets/GOODENDING/8.png");
    this->historiaFinalimg[9].loadFromFile("assets/GOODENDING/9.png");

    this->historiaFinalimg[10].loadFromFile("assets/BADENDING/1.png");
    this->historiaFinalimg[11].loadFromFile("assets/BADENDING/2.png");
}

void Menu::background(RenderWindow *window) {
    Sprite sprite0;
    sprite0.setTexture(mainmenu[0]);
    Sprite sprite1;
    sprite1.setTexture(mainmenu[1]);
    Sprite sprite2;
    sprite2.setTexture(mainmenu[2]);
    Sprite sprite3;
    sprite3.setTexture(mainmenu[3]);
    Sprite sprite4;
    sprite4.setTexture(mainmenu[4]);
    Sprite sprite5;
    sprite5.setTexture(mainmenu[5]);
    Sprite sprite6;
    sprite6.setTexture(mainmenu[6]);
    Sprite sprite7;
    sprite7.setTexture(mainmenu[7]);
    Sprite sprite8;
    sprite8.setTexture(mainmenu[8]);
    Sprite sprite9;
    sprite9.setTexture(mainmenu[9]);

    window->draw(sprite0);

    if (relogio.getElapsedTime().asMilliseconds() > 2000) {
        count = count + 1;
        relogio.restart();
        if (count > 9) {
            count = 9;
        }
    }

    switch (count) {
        case 1:
            window->draw(sprite1);
            break;
        case 2:
            window->draw(sprite2);
            break;
        case 3:
            window->draw(sprite3);
            break;
        case 4:
            window->draw(sprite4);
            break;
        case 5:
            window->draw(sprite5);
            break;
        case 6:
            window->draw(sprite6);
            break;
        case 7:
            window->draw(sprite7);
            break;
        case 8:
            window->draw(sprite8);
            break;
        case 9:
            window->draw(sprite9);
            break;
    }
}

void Menu::botoes(RenderWindow *window, int *control) {
    if (Keyboard::isKeyPressed(Keyboard::Down) &&
        botaorelogio.getElapsedTime().asMilliseconds() > 200) {
        botaocount++;
        botaorelogio.restart();
    }
    if (Keyboard::isKeyPressed(Keyboard::Up) &&
        botaorelogio.getElapsedTime().asMilliseconds() > 200) {
        botaocount--;
        botaorelogio.restart();
    }
    if (botaocount > 2) {
        botaocount = 0;
    }
    if (botaocount < 0) {
        botaocount = 2;
    }
    if (botaocount == 0) {
        botao[0].setSize(Vector2f(120, 0));
        botao[0].setPosition(Vector2f(190, 210));
        botao[0].setFillColor(Color(0, 0, 0, 0));
        botao[0].setOutlineColor(Color(255, 255, 255));
        botao[0].setOutlineThickness(1);
        window->draw(botao[0]);
    }
    if (botaocount == 1) {
        botao[1].setSize(Vector2f(200, 0));
        botao[1].setPosition(Vector2f(150, 280));
        botao[1].setFillColor(Color(0, 0, 0, 0));
        botao[1].setOutlineColor(Color(255, 255, 255));
        botao[1].setOutlineThickness(1);
        window->draw(botao[1]);
    }
    if (botaocount == 2) {
        botao[2].setSize(Vector2f(105, 0));
        botao[2].setPosition(Vector2f(195, 350));
        botao[2].setFillColor(Color(0, 0, 0, 0));
        botao[2].setOutlineColor(Color(255, 255, 255));
        botao[2].setOutlineThickness(1);
        window->draw(botao[2]);
    }
    if (Keyboard::isKeyPressed(Keyboard::Enter)) {
        switch (botaocount) {
            case 0:
                menutema.pause();
                temahist.setPlayingOffset(sf::seconds(15.f));
                temahist.play();
                *control = 4;

                break;
            case 1:
                *control = 2;
                break;
            case 2:
                *control = 3;
                break;
        }
    }
}

void Menu::credits(RenderWindow *window, int *control) {
    Sprite sprite;
    sprite.setTexture(creditos);
    window->draw(sprite);
    if (Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        *control = 1;
    }
}

void Menu::historia(RenderWindow *window, int *control, bool *dorme) {
    Sprite sprite0;
    sprite0.setTexture(historiaimg[0]);
    Sprite sprite1;
    sprite1.setTexture(historiaimg[1]);
    Sprite sprite2;
    sprite2.setTexture(historiaimg[2]);
    Sprite sprite3;
    sprite3.setTexture(historiaimg[3]);
    Sprite sprite4;
    sprite4.setTexture(historiaimg[4]);
    Sprite sprite5;
    sprite5.setTexture(historiaimg[5]);
    Sprite sprite6;
    sprite6.setTexture(historiaimg[6]);
    Sprite sprite7;
    sprite7.setTexture(historiaimg[7]);
    Sprite sprite8;
    sprite8.setTexture(historiaimg[8]);
    Sprite sprite9;
    sprite9.setTexture(historiaimg[9]);

    window->draw(sprite0);

    if (relogio.getElapsedTime().asMilliseconds() > 5000) {
        counthist = counthist + 1;
        relogio.restart();
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        counthist = 10;
    }

    switch (counthist) {
        case 1:
            window->draw(sprite1);
            break;
        case 2:
            window->draw(sprite2);
            break;
        case 3:
            window->draw(sprite3);
            break;
        case 4:
            window->draw(sprite4);
            break;
        case 5:
            window->draw(sprite5);
            break;
        case 6:
            window->draw(sprite6);
            break;
        case 7:
            window->draw(sprite7);
            break;
        case 8:
            window->draw(sprite8);
            break;
        case 9:
            window->draw(sprite9);
            break;
        case 10:
            *control = 0;
            temahist.pause();
            tema.play();
            *dorme = true;
            break;
    }
}

void Menu::historiaFinal(RenderWindow *window, int controle) {
    Sprite sprite0;
    sprite0.setTexture(historiaFinalimg[0]);
    Sprite sprite1;
    sprite1.setTexture(historiaFinalimg[1]);
    Sprite sprite2;
    sprite2.setTexture(historiaFinalimg[2]);
    Sprite sprite3;
    sprite3.setTexture(historiaFinalimg[3]);
    Sprite sprite4;
    sprite4.setTexture(historiaFinalimg[4]);
    Sprite sprite5;
    sprite5.setTexture(historiaFinalimg[5]);
    Sprite sprite6;
    sprite6.setTexture(historiaFinalimg[6]);
    Sprite sprite7;
    sprite7.setTexture(historiaFinalimg[7]);
    Sprite sprite8;
    sprite8.setTexture(historiaFinalimg[8]);
    Sprite sprite9;
    sprite9.setTexture(historiaFinalimg[9]);

    Sprite sprite10;
    sprite10.setTexture(historiaFinalimg[10]);
    Sprite sprite11;
    sprite11.setTexture(historiaFinalimg[11]);

    std::cout << countHistFinal << std::endl;

    if (controle == 1) {
        window->draw(sprite0);

        if (relogioFinal.getElapsedTime().asMilliseconds() > 5000) {
            countHistFinal = countHistFinal + 1;
            relogioFinal.restart();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            countHistFinal = 10;
        }

        switch (countHistFinal) {
            case 1:
                window->draw(sprite1);
                break;
            case 2:
                window->draw(sprite2);
                break;
            case 3:
                window->draw(sprite3);
                break;
            case 4:
                window->draw(sprite4);
                break;
            case 5:
                window->draw(sprite5);
                break;
            case 6:
                window->draw(sprite6);
                break;
            case 7:
                window->draw(sprite7);
                break;
            case 8:
                window->draw(sprite8);
                break;
            case 9:
                window->draw(sprite9);
                break;
            case 10:
                window->close();
                break;
        }
    }

    if (controle == 2) {
        window->draw(sprite10);

        if (countHistFinal < 2) {
            if (relogioFinal.getElapsedTime().asMilliseconds() > 20000) {
                countHistFinal = countHistFinal + 1;
                relogioFinal.restart();
            }
            if (countHistFinal == 1) {
                if (relogioFinal.getElapsedTime().asMilliseconds() > 5000) {
                    countHistFinal = countHistFinal + 1;
                    relogioFinal.restart();
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            countHistFinal = 2;
        }

        switch (countHistFinal) {
            case 1:
                window->draw(sprite11);
                break;
            case 2:
                window->close();
                break;
        }
    }
}