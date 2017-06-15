#include "view.h"
#include <QDebug>
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <QOpenGLWidget>
#include <QProcess>
#include <QApplication>
#include <QPainter>
#include <QPicture>
#include <QPixmap>


View::View()
{

}

View::View(QGraphicsScene *scene)
{
    setScene(scene);
//    sceneWidth = 5760 / 2;
//    sceneHeight = 1080 / 2;
    sceneWidth = 1440;
    sceneHeight = 540;
//    QPixmap image("../Textures/back.png");
//    scene->setBackgroundBrush(image.scaled(sceneWidth,sceneHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ShowMenu();

}

void View::CreateTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    timer->start(timerUpdateTime);
}

void View::SpawnPlayer(int type)
{
    int typeNew = type + (age * 10);
    Player * player = new Player(typeNew);
    this->scene()->addItem(player);
    playerList.append(player);
    player->setPos(150,sceneHeight - 50);

}

void View::SpawnEnemy(int type)
{
    int typeNew = type + (age * 10);
    Enemy * enemy = new Enemy(typeNew);
    this->scene()->addItem(enemy);
    enemyList.append(enemy);
    enemy->setPos(sceneWidth - 150 - enemy->sirka,sceneHeight - 50);
}

void View::SpawnBase()
{
    Base *myBase = new Base();
    Base *enemyBase = new Base();
    this->scene()->addItem(myBase);
    myBase->setPos(0,sceneHeight - 100);
    this->scene()->addItem(enemyBase);
    enemyBase->setPos(sceneWidth - enemyBase->sirka,sceneHeight - 100);
}

void View::MovePlayers()
{

    for (int i = 0; i < playerList.length(); ++i) {
        int speed = playerList[i]->speed;
        QPointF smer(speed,0);
        playerList[i]->setPos(playerList[i]->pos()+smer);
    }
}

void View::MoveEnemyPlayers()
{

    for (int i = 0; i <enemyList.length(); ++i) {
        int speed = enemyList[i]->speed;
        speed = speed * -1;
        QPointF smer(speed,0);
        enemyList[i]->setPos(enemyList[i]->pos()+smer);
    }
}

void View::Update()
{
//    if(playerList.length() != 0 && enemyList.length() != 0){//na vyzkouseni kvuli bugu na zacatku
    if(playerList.length() != 0 || enemyList.length() != 0){
        MovePlayers();
        MoveEnemyPlayers();
    }
    frames++;//pocitani framu pro fps
    if(cooldown<50){
        cooldown++;
//        qDebug()<<cooldown;
    }
    Collision();
}

void View::ShowMenu()
{
    qDebug() << "INFO: zobrazuji menu";
    Background *background = new Background("0-background.png",sceneWidth,sceneHeight);
    this->scene()->addItem(background);
}

void View::Collision()
{
    for (int x = 0; x < playerList.length(); ++x) {//kolize my player s enemy player
        QList<QGraphicsItem *> list = playerList[x]->collidingItems();
        foreach(QGraphicsItem * i, list)
        {
            Enemy * enemy=dynamic_cast<Enemy *>(i);
            if(enemy){
                qDebug() <<"Colide with enemy";
                playerList[x]->speed = 0;
                if(enemy->health <= 0){
                    scene()->removeItem(enemy);
                       playerList[x]->speed = 2;

                }
                enemy->health = enemy->health - playerList[x]->damage/10;
            }
        }
    }
    for (int x = 0; x < enemyList.length(); ++x) {//kolize enemy player s my player
        QList<QGraphicsItem *> list = enemyList[x]->collidingItems();
        foreach(QGraphicsItem * i, list)
        {
            Player * player=dynamic_cast<Player *>(i);
            if(player){
                qDebug() <<"Colide with player";
                enemyList[x]->speed = 0;
            }

        }
    }
    for (int x = 0; x < playerList.length(); ++x) {//kolize my player s enemy base
        QList<QGraphicsItem *> list = playerList[x]->collidingItems();
        foreach(QGraphicsItem * i, list)
        {
            Base * enemyBase=dynamic_cast<Base *>(i);
            if(enemyBase){
                qDebug() <<"Colide with enemy base";
                playerList[x]->speed = 0;
            }

        }
    }
    for (int x = 0; x < enemyList.length(); ++x) {//kolize enemy player s my base
        QList<QGraphicsItem *> list = enemyList[x]->collidingItems();
        foreach(QGraphicsItem * i, list)
        {
            Base * myBase=dynamic_cast<Base *>(i);
            if(myBase){
                qDebug() <<"Colide with my base";
                enemyList[x]->speed = 0;
            }

        }
    }
    for (int x = 0; x < playerList.length(); ++x) {//kolize my player s myplayer
        QList<QGraphicsItem *> list = playerList[x]->collidingItems();
        foreach(QGraphicsItem * i, list)
        {
            Player * player=dynamic_cast<Player *>(i);
            if(player){
                if(player->pos().x()>playerList[x]->pos().x())
                   playerList[x]->speed = 0;

                qDebug() <<"Colide with my playerrfgrdg";
            }

        }
    }
}

void View::DisplayControls()
{

}

void View::StartGame()
{
    qDebug() << "INFO: starting game";
    status = running;
    CreateTimer();
    SpawnBase();
}

void View::Attack()
{

}

void View::System(QString data)
{
    QStringList list = data.split(" ");
    if(list[0] == "button"){
        if(list[1] == "startgame"){
            if(status == menu){
                StartGame();
            }
        }
        else if(list[1] == "playpause"){
            if(status == running){
                status = stopped;
               PauseGamse();
            }
            else if(status == stopped){
                status = running;
                UnpauseGame();
            }
        }
    }else if(list[0] == "spawn"){
        if(status == running){
            if((playerList.length() + enemyList.length()) <= playerEntityLimit && cooldown >= 50){
                if(list[1] == "basic"){
                    qDebug() << "INFO: spawnut player basic";
                    SpawnPlayer(1);
                    SpawnEnemy(1);
                    cooldown = 0;
                }
                else if(list[1] == "long"){
                    qDebug() << "INFO: spawnut player long";
                    SpawnPlayer(2);
                    cooldown = 0;
                }
                else if(list[1] == "high"){
                    qDebug() << "INFO: spawnut player high";
                    SpawnPlayer(3);
                    cooldown = 0;
                }
                else if(list[1] == "special"){
                    qDebug() << "INFO: spawnut player special";
                    SpawnPlayer(4);
                    cooldown = 0;
                }
                else{
                    qDebug() << "ERROR: neznamy parametr funkce spawn";
                }
            }
            else{
                qDebug() << "INFO: nelze spawnout dalsi entitu - dosazen limit / cooldown";
            }
        }
        else{
            qDebug() << "INFO: nemuzes klikat na useles tlacitka";
        }
    }
    else{
        qDebug() << "ERROR: neznama funkce";
    }
}

void View::PauseGamse()
{
    qDebug() << "INFO: pausing game";
}

void View::UnpauseGame()
{
    qDebug() << "INFO: resumming game";
}

void View::keyPressEvent(QKeyEvent *event)
{

}

void View::keyReleaseEvent(QKeyEvent *event)
{

}

void View::CreateGame()
{
    qDebug() << "INFO: creating game";
}
