#include "base.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>
#include "view.h"
#include "mainwindow.h"

Base::Base()
{

    setTransformOriginPoint(sirka/2, sirka/2);
}

QRectF Base::boundingRect() const
{
    return QRectF(0,0,sirka,vyska);
}

QPainterPath Base::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Base::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::black)); //upravit
    painter->setPen(Qt::black);
    painter->drawPath(shape());
    //QImage image("../Age-Of-Wars-master/base.png");//nazev je nazev souboru i s priponou
    //painter->drawImage(QPoint(0,0),image.scaled(sirka,vyska));
}
