#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "view.h"
#include <QGraphicsScene>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    View *view;


public slots:
    void on_actionExit_triggered();
    void FpsCounter();

private slots:
    void on_buttonStartGame_clicked();

    void on_buttonPlayPause_clicked();

    void on_buttoSpawnBasic_clicked();

    void on_buttonSpawnLong_clicked();

    void on_buttonSpawnHigh_clicked();

    void on_buttonSpawnSpecial_clicked();

private:
     Ui::MainWindow *ui;
     QGraphicsScene scene;
     QTimer *timerFps;
};

#endif // MAINWINDOW_H
