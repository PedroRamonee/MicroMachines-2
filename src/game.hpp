#ifndef GAME_HPP_
#define GAME_HPP_
#include "bot.hpp"
#include "map.hpp"
#include "player.hpp"

class Game {
   private:
    Mapa *mapa = new Mapa();
    Player *jogador = new Player();
    Event event;
    Bot *bot = new Bot();

    FloatRect PlayerHitbox;
    FloatRect BotHitbox;
    FloatRect HitboxCollide;

    Clock timer;

    bool colissionDetected = false;

   public:
    void Run(RenderWindow *window);
    void entityRender(RenderWindow *window);
    void Render(RenderWindow *window);
    void testColission();
};

#endif  // GAME_HPP_