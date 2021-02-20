#ifndef __SNAKE_HEADER__
#define __SNAKE_HEADER__

#include <vector>

struct coordinates {
    int x, y;
    coordinates(int _x, int _y) : x(_x), y(_y) {}; 
};

class Snake {
    private:
         std::vector <coordinates> snake_pos;
    public:
        Snake(int x_start, int y_start);
        ~Snake();
        void move_head(int direction);
        void move_body();
        void move_body_grow();
        int get_length();
    friend class snakeGame;
    friend class MainWindow;
};


#endif 
