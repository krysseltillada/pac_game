#include "Game.h"

bool Game::GameState ()
{
    return if_GameOver;
}

void Game::event ()
{
        switch (_getch()) {
        case 'w':
            key = UP;
            break;
        case 's':
            key = DOWN;
            break;
        case 'a':
            key = LEFT;
            break;
        case 'd':
            key = RIGHT;
            break;
        default:
            break;
        }
}

void Game::update ()
{
    int prevY = 0, prevX = 0;

    switch (key) {
    case UP: {
        prevY = pac_y;
        prevX = pac_x;

        --pac_y;
        if (walls[pac_y][pac_x] == '#') {
            ++pac_y;
        } else if (walls[pac_y][pac_x] == '*') {
            walls[pac_y][pac_x] = ' ';
            --n_of_fruits;
        }
        break;
    }
    case DOWN:{
        prevY = pac_y;
        prevX = pac_x;

        ++pac_y;
          if (walls[pac_y][pac_x] == '#') {
            --pac_y;
        } else if (walls[pac_y][pac_x] == '*') {
            walls[pac_y][pac_x] = ' ';
            --n_of_fruits;
        }
        break;
    }
    case LEFT: {
        prevY = pac_y;
        prevX = pac_x;

        --pac_x;
          if (walls[pac_y][pac_x] == '#') {
            ++pac_x;
        } else if (walls[pac_y][pac_x] == '*') {
            walls[pac_y][pac_x] = ' ';
            --n_of_fruits;
        }
        break;
    }
    case RIGHT: {
        prevY = pac_y;
        prevX = pac_x;

        ++pac_x;
          if (walls[pac_y][pac_x] == '#') {
            --pac_x;
        } else if (walls[pac_y][pac_x] == '*') {
            walls[pac_y][pac_x] = ' ';
            --n_of_fruits;
        }
        break;
    }
    default:
        break;
    }

    walls[prevY][prevX] = ' ';

    for (int y = 0; y != height; ++y) {
        for (int x = 0; x != width; ++x) {
            walls[pac_y][pac_x] = 'O';
        }
    }

    if (n_of_fruits == 0)
        if_GameOver = true;

}

void Game::generate_fruits ()
{
    for (int y = 0; y != height; ++ y) {
        for (int x = 0; x != width; ++x) {
            if (walls[y][x] == ' ') {
                walls[y][x] = '*';
                ++n_of_fruits;
            }
        }
    }

    --n_of_fruits;
}

void Game::Clear ()
{
    system ("cls");
}

void Game::draw ()
{

   for (int y = 0; y != height; ++y) {
    for (int x = 0; x != width; ++x)  {
        std::cout << walls[y][x];
    }
    std::cout << std::endl;
   }

   std::cout << "y: " << pac_y << std::endl
             << "x: " << pac_x << std::endl;

   std::cout << "fruits left: " << n_of_fruits << std::endl;
}


void Game::generate_map ()
{
    for (int y = 0; y != height; ++y) {
        for (int x = 0; x != width; ++x) {
            walls[y][x] = ' ';
        }
    }
}

void Game::load_map ()
{
    std::fstream load("map.txt", std::ifstream::in);
    std::string line;

    int y = 0, x = 0;

    while (std::getline (load, line)) {
            for (auto c : line) {
                if (c == '#') {
                    walls[y][x] = c;
                    ++x;
                }
                else {
                    walls[y][x] = c;
                    ++x;
                }
            }
    }

}
