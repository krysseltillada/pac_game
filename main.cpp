#include "Game.h"

int main ()
{
    Game game;

        game.generate_map();
        game.load_map();
        game.generate_fruits();

        while (!game.GameState()) {
            game.draw();
            game.event();
            game.update();
            game.Clear();
        }

    return 0;
}
