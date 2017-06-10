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
    this->setCentralWidget(view);
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
