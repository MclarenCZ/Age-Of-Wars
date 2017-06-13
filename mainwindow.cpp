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
    view = new View(&scene);
//    this->setCentralWidget(view);
    this->ui->verticalLayout->addWidget(view);

    timerFps = new QTimer(this);
    connect(timerFps, SIGNAL(timeout()), this, SLOT(FpsCounter()));
    timerFps->start(1000);
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

void MainWindow::FpsCounter()
{
    qDebug() << view->frames << "FPS";
    view->frames = 0;
}

void MainWindow::on_buttonStartGame_clicked()
{
//    object.System("button startgame");
   view->System("button startgame");
}

void MainWindow::on_buttonPlayPause_clicked()
{
    view->System("button playpause");
}

void MainWindow::on_buttoSpawnBasic_clicked()
{
    view->System("spawn basic");
}

void MainWindow::on_buttonSpawnLong_clicked()
{
    view->System("spawn long");
}

void MainWindow::on_buttonSpawnHigh_clicked()
{
    view->System("spawn high");
}

void MainWindow::on_buttonSpawnSpecial_clicked()
{
    view->System("spawn special");
}
