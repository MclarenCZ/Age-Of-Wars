#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QKeyEvent>
#include <QList>
#include "player.h"
#include "base.h"
#include "turret.h"
#include "bullet.h"
#include "mainwindow.h"


class View : public QGraphicsView
{
    Q_OBJECT
public:
    View();
    View(QGraphicsScene *scene);
    void CreateTimer();
    enum gameStatus{menu,stopped,running};
    gameStatus status = menu;
    void SpawnPlayer(bool isEnemy, QString type);
    void SpawnBase();


public slots:
    void Update();
    void ShowMenu();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    int width;
    int height;
    Player *player;
    Base *mybase;
    Base *enemybase;
    QList<Player *> playerList;
    QList<Player *> enemyList;

    QTimer *timer;
    QGraphicsTextItem *scoreItem;
    QGraphicsTextItem *gameOverItem;

    void CreateGame();

signals:





};

#endif // VIEW_H
