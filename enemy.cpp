#include "enemy.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>
#include "view.h"
#include "mainwindow.h"

Enemy::Enemy(int type)
{
    setTransformOriginPoint(sirka/2, sirka/2);
    switch (type) {
    case 001:
        health = 100;
        cooldown = 5;//in sec
        break;
    case 002:
        health = 80;
        cooldown = 10;//in sec
        break;
    case 003:
        health = 150;
        cooldown = 15;//in sec
        break;
    case 004:
        health = 250;
        cooldown = 20;//in sec
        break;
    case 011:
        health = 150;
        cooldown = 5;//in sec
        break;
    case 012:
        health = 130;
        cooldown = 10;//in sec
        break;
    case 013:
        health = 200;
        cooldown = 15;//in sec
        break;
    case 014:
        health = 300;
        cooldown = 20;//in sec
        break;
    case 021:
        health = 200;
        cooldown = 5;//in sec
        break;
    case 022:
        health = 180;
        cooldown = 10;//in sec
        break;
    case 023:
        health = 250;
        cooldown = 15;//in sec
        break;
    case 024:
        health = 350;
        cooldown = 20;//in sec
        break;
    case 031:
        health = 250;
        cooldown = 5;//in sec
        break;
    case 032:
        health = 230;
        cooldown = 10;//in sec
        break;
    case 033:
        health = 300;
        cooldown = 15;//in sec
        break;
    case 034:
        health = 400;
        cooldown = 20;//in sec
        break;
    case 041:
        health = 300;
        cooldown = 5;//in sec
        break;
    case 042:
        health = 280;
        cooldown = 10;//in sec
        break;
    case 043:
        health = 350;
        cooldown = 15;//in sec
        break;
    case 044:
        health = 450;
        cooldown = 20;//in sec
        break;
    default:
        break;
    }
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
