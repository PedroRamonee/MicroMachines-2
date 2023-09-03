#include "src/game.hpp"
#include "src/menu.hpp"

int main() {
    RenderWindow window(VideoMode(500, 500), "MicroMachines 2 Remake");

    View defaultWindow = window.getDefaultView();

    Game *game = new Game();
    game->Run(&window, defaultWindow);

    delete game;

    return 0;
}
