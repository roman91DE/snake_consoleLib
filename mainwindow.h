#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "add_existing/ConsoleWindow.h"
#include "add_existing/snake.h"
#include "add_existing/snakegame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public ConsoleWindow {
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    void onRefresh() override;
    void draw_current();

private:
    Ui::MainWindow *ui;
    snakeGame *game;
};
#endif // MAINWINDOW_H
