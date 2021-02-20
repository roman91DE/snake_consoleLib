#include "snakegame.h"
#include "snake.h"
#include <random>
#include <iostream>




snakeGame::snakeGame(int _x_max, int _y_max)
: x_max(_x_max), y_max(_y_max), cur_direction(1), apple(false), grow(false) {
    snake = new Snake(x_max/2, y_max/2);
}


snakeGame::~snakeGame() {
    delete snake;
    //std::cout << "snakeGame deleted!\n";
};

void snakeGame::generate_apple() {
    while (!apple) {
        bool flag = true;
        x_apple = rand()%x_max;
        y_apple = rand()%y_max;
        for (auto &it: snake->snake_pos) {
            if ((it.x == x_apple) && (it.y == y_apple)) { flag=false; }
        }
        if (flag) { apple = true; }
    }
}


int snakeGame::get_score() {
    return snake->get_length();
}


bool snakeGame::possible_move(int cur_direction) {
    int x = snake->snake_pos[0].x;
    int y = snake->snake_pos[0].y;
    // links
    if      (cur_direction == 1) { x--; }
    // rechts
    else if (cur_direction == 2) { x++; }
    // hoch
    else if (cur_direction == 3) { y--; }
    // runter
    else if (cur_direction == 4) { y++; }

    // spielfeldrand
    if ( ( (x>=x_max)||(y>=y_max) ) || ( (x<0) || (y<0) ) )  { return false; }
    // schlange im weg
    for (int i = 1; i < snake->get_length(); i++) {
        if ( (x == snake->snake_pos[i].x) && (y == snake->snake_pos[i].y) ) { return false; }
    }

    // apfel gefressen
    if ((x == x_apple) && (y == y_apple)) {
        grow = true;
        apple = false;
        return true;
    }
    return true;
}
