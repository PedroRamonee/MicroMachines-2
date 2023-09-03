#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace sf;

class Menu {
   private:
    Texture mainmenu[10];
    Music menutema;
    Clock relogio;
    int count;
    RectangleShape botao[3];
    int botaocount;
    Clock botaorelogio;
    Texture historiaimg[10];
    Texture creditos;
    Music temahist;
    Clock relogiohist;
    int counthist;
    Texture historiaFinalimg[12];
    int countHistFinal=-1;
    Clock relogioFinal;

   public:
    Music tema;
    Music musicasFinal[4];
    Menu();
    void background(RenderWindow *window);
    void botoes(RenderWindow *window, int *control);
    void credits(RenderWindow *window, int *control);
    void historia(RenderWindow *window, int *control, bool *dorme);
    void historiaFinal(RenderWindow *window, int controle);
};

#endif  // MENU_HPP_