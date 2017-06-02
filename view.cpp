#include "view.h"
#include "mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QtMath>
#include <QGraphicsSceneMouseEvent>
#include <time.h>

View::View()
{

}

View::View(QGraphicsScene *scene)
{
    setScene(scene);
    this->scene()->setBackgroundBrush(QBrush(QColor(230,230,230)));
}
