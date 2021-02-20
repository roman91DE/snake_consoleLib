#include "snake.h"
#include <iostream>

Snake::Snake(int x_start, int y_start) {
    snake_pos.push_back(coordinates(x_start, y_start));
}

Snake::~Snake() {
    //std::cout << "Snake deleted!\n";
}

void Snake::move_head(int direction) {
    // left
    if      (direction == 1) snake_pos[0].x--;
    // right
    else if (direction == 2) snake_pos[0].x++;
    // up
    else if (direction == 3) snake_pos[0].y--;
    // down
    else if (direction == 4) snake_pos[0].y++;
    }


void Snake::move_body() {
    for (unsigned int i = get_length(); i>0; i--) {
        snake_pos[i].x = snake_pos[i-1].x;
        snake_pos[i].y = snake_pos[i-1].y;
    }
}


void Snake::move_body_grow() {
    coordinates tail = snake_pos[get_length()-1];
    move_body();
    snake_pos.push_back(tail);
}


int Snake::get_length() {
    return snake_pos.size();
}
