#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <qevent.h>
#include <QFileDialog>

class View : public QGraphicsView
{
public:
    View();
    View(QGraphicsScene *scene);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseWheelEvent(QGraphicsSceneWheelEvent *event);

    QGraphicsItem *player;
};

#endif // VIEW_H
