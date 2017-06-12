#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QKeyEvent>
#include <QList>
#include "player.h"
#include "enemy.h"
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
    void SpawnPlayer(QString type);
    void SpawnEnemy(QString type);
    void SpawnBase();
    void MovePlayers();
    void MoveEnemyPlayers();
    void Collision();
    void DisplayControls();
    void StartGame();
    void Attack();
    void System(QString data);
    void PauseGamse();

    int sceneWidth;
    int sceneHeight;
    enum gameStatus{menu,stopped,running};
    gameStatus status = menu;
    int myHighScore;
    QString myUsername;
    int globalHighscoreScore;
    QString globalHighscoreUsername;


public slots:
    void Update();
    void ShowMenu();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    void CreateGame();

    Player *player;
    Enemy *enemy;
    Base *mybase;
    Base *enemybase;
    QTimer *timer;
    QGraphicsTextItem *scoreItem;
    QGraphicsTextItem *gameOverItem;

    QList<Player *> playerList;
    QList<Enemy *> enemyList;

signals:





};

#endif // VIEW_H
