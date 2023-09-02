#ifndef GAME_HPP_
#define GAME_HPP_
#include "bot.hpp"
#include "checkpoint.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "obstaculos.hpp"
#include "player.hpp"

class Game {
   private:
    Mapa *mapa = new Mapa();
    Player *jogador = new Player();
    Obstaculo *obstaculos = new Obstaculo();
    Event event;
    Bot *bot = new Bot();
    Checkpoint Checkpoints;
    Obstaculo personagens;
    Sound colisionSound;
    SoundBuffer colisionBuffer;
    SoundBuffer outBuffer;
    Sound outSound;
    bool control;
    int controlPanel;
    Menu *menu;
    bool dorme = false;
    int Turns;
    int controlCheckPoints;
    int minutos;

    FloatRect PlayerHitbox;
    FloatRect BotHitbox;

    Clock timer;
    Clock clock;
    Clock object;
    Time elapsed1;

    bool colissionDetected = false;
    bool objectCollide = false;

    Font fonte;
    Text volta;
    Text tempo;

   public:
    Game();
    void entityRender(RenderWindow *window);
    void Render(RenderWindow *window);
    void testColission();
    void colissionFunctions(RenderWindow *window);
    void collideObject(RenderWindow *window);
    void renderFunctions(RenderWindow *window);
    void Run(RenderWindow *window);
    void testCheckpoint();
    void testObstaculos();
    void countTurns(RenderWindow *window);
    void temporizador(RenderWindow *winow);
};

#endif  // GAME_HPP_