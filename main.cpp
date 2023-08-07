#include "src/game.hpp"

int main() {
    RenderWindow window(VideoMode(400, 400), "MicroMachines 2 Remake");

    Game *game = new Game();
    game->Run(&window);

    delete game;

    return 0;
}
