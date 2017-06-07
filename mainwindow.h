#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <view.h>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:

private:
     Ui::MainWindow *ui;
     QGraphicsScene scene;
};

#endif // MAINWINDOW_H
