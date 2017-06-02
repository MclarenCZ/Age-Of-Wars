#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "view.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new View(&scene);
    scene.setSceneRect(0,0,0,0);
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
