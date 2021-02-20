#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>

// macbook memory check command
// memcheck /Users/roman/dev/build-snakeGUI-Desktop_Qt_5_15_2_clang_64bit-Debug/snakeGUI.app/Contents/MacOS/snakeGUI


MainWindow::MainWindow()
: ConsoleWindow() {
     game = new snakeGame(getWidth(), getHeight());
}


MainWindow::~MainWindow() {
    if (game != Q_NULLPTR)
        delete game;
}


void MainWindow::onRefresh() {
    if (!game->apple) { game->generate_apple(); }
    draw_current();
    if (getPressedKey() == CURSOR_LEFT)              game->cur_direction = 1;
    if (getPressedKey() == CURSOR_RIGHT)             game->cur_direction = 2;
    if (getPressedKey() == CURSOR_UP)                game->cur_direction = 3;
    if (getPressedKey() == CURSOR_DOWN)              game->cur_direction = 4;
    if (!game->possible_move(game->cur_direction)) {
        clear();
        writeString(getWidth()/2,getHeight()/2,"Snake ist Tod");
        writeString(getWidth()/2,(getHeight()/2)+2,"Score=");
        writeString((getWidth()/2)+6,(getHeight()/2)+2,std::to_string(game->get_score()));
        delete game;
        game = Q_NULLPTR;
        game = new snakeGame(getWidth(), getHeight());
    }
    if (game->grow) {
        game->snake->move_body_grow();
        game->grow = false;
        game->apple = false;
    }
    else { game->snake->move_body(); }
    game->snake->move_head(game->cur_direction);
}

void MainWindow::draw_current() {
    clear();
    // draw apple
    setCharacter(game->x_apple, game->y_apple, 'o');
    // draw snake
    for (auto &it: game->snake->snake_pos) {
        setCharacter(it.x, it.y, 'x');
    }
}
