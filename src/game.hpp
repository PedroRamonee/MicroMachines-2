#ifndef GAME_HPP_
#define GAME_HPP_
#include "map.hpp"
#include "player.hpp"

class Game {
   public:
    void Run(RenderWindow *window);
    void Render(RenderWindow *window, Player *jogador, Mapa *mapa);
};

#endif  // GAME_HPP_