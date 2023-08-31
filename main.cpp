#include "src/game.hpp"
#include "src/menu.hpp"

int main() {
    RenderWindow window(VideoMode(500, 500), "MicroMachines 2 Remake");

    Game *game = new Game();
    game->Run(&window);

    delete game;

    return 0;
}
