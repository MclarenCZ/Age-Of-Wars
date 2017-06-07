#include "view.h"
#include <QDebug>
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <QOpenGLWidget>
#include <QProcess>
#include <QApplication>


View::View()
{

}

View::View(QGraphicsScene *scene)
{
    setScene(scene);//musi byt pred pouzitim this->scene()
    ShowMenu();

}

void View::CreateTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    timer->start(30);
}

void View::SpawnPlayer(bool isEnemy, QString type)
{
    if(!isEnemy){
        Player * player = new Player();
        this->scene()->addItem(player);
        playerList.append(player);
    }
}

void View::SpawnBase()
{
    Base *myBase = new Base();
    Base *enemyBase = new Base();
    this->scene()->addItem(myBase);
    myBase->setPos(0,100);//upravit
    this->scene()->addItem(enemyBase);
    enemyBase->setPos(1000,100);//upravit
}

void View::Update()
{

}

void View::ShowMenu()
{
    //potom s zobrazenym menu a tlacitky
    status = running;
    SpawnBase();
}

void View::keyPressEvent(QKeyEvent *event)
{

}

void View::keyReleaseEvent(QKeyEvent *event)
{

}

void View::CreateGame()
{

}
