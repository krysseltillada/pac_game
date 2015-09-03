#ifndef GAME_HEADER
#define GAME_HEADER

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <conio.h>

class Game {
public:
    bool GameState ();
    void Clear ();
    void event ();
    void draw ();
    void update ();
    void load_map ();
    void generate_map ();
    void generate_fruits ();

private:
    enum KeyInput {
        LEFT,
        RIGHT,
        UP,
        DOWN
        };

    KeyInput key;

    bool if_GameOver = false;

    char walls[20][40];

    std::string Movement = "UP";

    static const int height = 19, width = 40;
    int pac_y = 1, pac_x = 2;
    int n_of_fruits = 0;


};

#endif // GAME_HEADER
