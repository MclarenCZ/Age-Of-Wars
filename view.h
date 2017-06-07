#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QKeyEvent>
#include <QList>
#include "player.h"
#include "mainwindow.h"


class View : public QGraphicsView
{
    Q_OBJECT
public:
    View();
    View(QGraphicsScene *scene);
    void CreateTimer();


public slots:
    void Update();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    int width;
    int height;
    Player *player;

    QTimer *timer;
    QGraphicsTextItem *scoreItem;
    QGraphicsTextItem *gameOverItem;
signals:





};

#endif // VIEW_H
