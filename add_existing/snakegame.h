#ifndef SNAKEGAME_H
#define SNAKEGAME_H

class Snake;

class snakeGame {

private:
    Snake *snake;
    int x_max, y_max;
    int cur_direction;
    int x_apple, y_apple;
    bool apple, grow;
public:
    snakeGame(int _x_max, int _y_max);
    ~snakeGame();
    void generate_apple();
    int get_score();
    bool possible_move(int cur_direction);

friend class MainWindow;
};

#endif // SNAKEGAME_H


