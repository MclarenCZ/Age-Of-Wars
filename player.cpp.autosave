#include "player.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>
#include "view.h"
#include "mainwindow.h"

Player::Player()
{
    setTransformOriginPoint(sirka/2, sirka/2);
}

QRectF Player::boundingRect() const
{
    return QRectF(0,0,sirka,vyska);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::red)); //upravit
    painter->setPen(Qt::red);
    painter->drawPath(shape());
}
