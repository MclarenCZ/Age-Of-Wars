#include "enemy.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>
#include "view.h"
#include "mainwindow.h"

Player::Player(QString type)
{
    setTransformOriginPoint(sirka/2, sirka/2);
    switch (type) {
    case "0-basic":
        health = 100;
        cooldown = 5;//in sec
        break;
    case "0-long":
        health = 80;
        cooldown = 10;//in sec
        break;
    case "0-high":
        health = 150;
        cooldown = 15;//in sec
        break;
    case "0-special":
        health = 250;
        cooldown = 20;//in sec
        break;
    case "1-basic":
        health = 150;
        cooldown = 5;//in sec
        break;
    case "1-long":
        health = 130;
        cooldown = 10;//in sec
        break;
    case "1-high":
        health = 200;
        cooldown = 15;//in sec
        break;
    case "1-special":
        health = 300;
        cooldown = 20;//in sec
        break;
    case "2-basic":
        health = 200;
        cooldown = 5;//in sec
        break;
    case "2-long":
        health = 180;
        cooldown = 10;//in sec
        break;
    case "2-high":
        health = 250;
        cooldown = 15;//in sec
        break;
    case "2-special":
        health = 350;
        cooldown = 20;//in sec
        break;
    case "3-basic":
        health = 250;
        cooldown = 5;//in sec
        break;
    case "3-long":
        health = 230;
        cooldown = 10;//in sec
        break;
    case "3-high":
        health = 300;
        cooldown = 15;//in sec
        break;
    case "3-special":
        health = 400;
        cooldown = 20;//in sec
        break;
    case "0-basic":
        health = 300;
        shield = 0;
        cooldown = 5;//in sec
        break;
    case "0-long":
        health = 280;
        cooldown = 10;//in sec
        break;
    case "0-high":
        health = 350;
        cooldown = 15;//in sec
        break;
    case "0-special":
        health = 450;
        cooldown = 20;//in sec
        break;
    default:
        break;
    }
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
