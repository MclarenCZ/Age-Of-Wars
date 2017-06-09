#include "enemy.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>
#include "view.h"
#include "mainwindow.h"

Enemy::Enemy()
{
    setTransformOriginPoint(sirka/2, sirka/2);

}

QRectF Enemy::boundingRect() const
{
    return QRectF(0,0,sirka,vyska);
}

QPainterPath Enemy::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::red)); //upravit
    painter->setPen(Qt::red);
    painter->drawPath(shape());
}
