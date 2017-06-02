#include "player.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>
#include "view.h"
#include "mainwindow.h"

Player::Player(QString nazev, QColor barva, int sirka, int vyska)
{
    this->barva = barva;
    this->nazev = nazev;
    this->sirka = sirka - 1;
    this->vyska = vyska - 1;
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
    QImage image("../Resources/"+nazev+".png");
    painter->drawImage(QPoint(0,0),image.scaled(sirka,vyska));
}
