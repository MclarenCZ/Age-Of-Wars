#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QPainterPath>
#include <QPainter>
#include "player.h"
#include "view.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    View *view = new View(&scene);
//    this->setCentralWidget(view);
    this->ui->verticalLayout->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionExit_triggered()
{
//    this->CloseApplication();
    this->close();
}

void MainWindow::on_buttonStartGame_clicked()
{
    View::System("button startgame");
}

void MainWindow::on_buttonPlayPause_clicked()
{
    View::System("button playpause");
}

void MainWindow::on_buttoSpawnBasic_clicked()
{
    View::System("spawn basic");
}

void MainWindow::on_buttonSpawnLong_clicked()
{
    View::System("spawn long");
}

void MainWindow::on_buttonSpawnHigh_clicked()
{
    View::System("spawn high");
}

void MainWindow::on_buttonSpawnSpecial_clicked()
{
    View::System("spawn special");
}
