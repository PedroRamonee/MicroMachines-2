#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

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
    Music tema;

   public:
    Menu();
    void background(RenderWindow *window);
    void botoes(RenderWindow *window, int *control);
    void credits(RenderWindow *window, int *control);
    void historia(RenderWindow *window, int *control, bool *dorme);
};

#endif  // MENU_HPP_