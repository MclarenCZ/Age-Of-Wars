#include "enemy.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>
#include "view.h"
#include "mainwindow.h"

Player::Player(int type)
{
    setTransformOriginPoint(sirka/2, sirka/2);
    switch (type) {
    case 001:
        health = 100;
        cooldown = 5;//in sec
        filename = "0-basic.png";
        color = Qt::red;
        break;
    case 002:
        health = 80;
        cooldown = 10;//in sec
        filename = "0-long.png";
        color = Qt::green;
        break;
    case 003:
        health = 150;
        cooldown = 15;//in sec
        filename = "0-high.png";
        color = Qt::blue;
        break;
    case 004:
        health = 250;
        cooldown = 20;//in sec
        filename = "0-special.png";
        color = Qt::yellow;
        break;
    case 011:
        health = 150;
        cooldown = 5;//in sec
        filename = "1-basic.png";
        break;
    case 012:
        health = 130;
        cooldown = 10;//in sec
        filename = "1-long.png";
        break;
    case 013:
        health = 200;
        cooldown = 15;//in sec
        filename = "1-high.png";
        break;
    case 014:
        health = 300;
        cooldown = 20;//in sec
        filename = "2-special.png";
        break;
    case 021:
        health = 200;
        cooldown = 5;//in sec
        filename = "2-basic.png";
        break;
    case 022:
        health = 180;
        cooldown = 10;//in sec
        filename = "2-long.png";
        break;
    case 023:
        health = 250;
        cooldown = 15;//in sec
        filename = "2-high.png";
        break;
    case 024:
        health = 350;
        cooldown = 20;//in sec
        filename = "2-special.png";
        break;
    case 031:
        health = 250;
        cooldown = 5;//in sec
        filename = "3-basic.png";
        break;
    case 032:
        health = 230;
        cooldown = 10;//in sec
        filename = "3-long.png";
        break;
    case 033:
        health = 300;
        cooldown = 15;//in sec
        filename = "3-high.png";
        break;
    case 034:
        health = 400;
        cooldown = 20;//in sec
        filename = "3-special.png";
        break;
    case 041:
        health = 300;
        cooldown = 5;//in sec
        filename = "4-basic.png";
        break;
    case 042:
        health = 280;
        cooldown = 10;//in sec
        filename = "4-long.png";
        break;
    case 043:
        health = 350;
        cooldown = 15;//in sec
        filename = "4-high.png";
        break;
    case 044:
        health = 450;
        cooldown = 20;//in sec
        filename = "4-special.png";
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
    painter->setBrush(QBrush(color)); //upravit
    painter->setPen(Qt::red);
    painter->drawPath(shape());
//    QImage image("../Textures/" + filename);
    //painter->drawImage(QPoint(0,0),image.scaled(sirka,vyska));
}
