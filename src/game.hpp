#ifndef GAME_HPP_
#define GAME_HPP_
#include "bot.hpp"
#include "checkpoint.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "player.hpp"

class Game {
   private:
    Mapa *mapa = new Mapa();
    Player *jogador = new Player();
    Event event;
    Bot *bot = new Bot();
    Checkpoint Checkpoints;
    Sound colisionSound;
    SoundBuffer colisionBuffer;
    SoundBuffer outBuffer;
    Sound outSound;
    bool control;
    int controlPanel;
    Menu *menu;
    bool dorme = false;

    FloatRect PlayerHitbox;
    FloatRect BotHitbox;

    Clock timer;

    bool colissionDetected = false;

   public:
    Game();
    void entityRender(RenderWindow *window);
    void Render(RenderWindow *window);
    void testColission();
    void colissionFunctions(RenderWindow *window);
    void renderFunctions(RenderWindow *window);
    void Run(RenderWindow *window);
    void testCheckpoint();
};

#endif  // GAME_HPP_