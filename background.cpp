#include "background.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>
#include "view.h"
#include "mainwindow.h"

Background::Background(QString filename,int sirka,int vyska)
{
    setTransformOriginPoint(sirka/2, sirka/2);
    this->file = filename;
    this->sirka = sirka;
    this->vyska = vyska;
}

QRectF Background::boundingRect() const
{
    return QRectF(0,0,sirka,vyska);
}

QPainterPath Background::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image("../Textures/" + file);
    painter->setBrush((QPoint(0,0),image/*.scaled(sirka,vyska)*/)); //upravit
    painter->setPen(Qt::black);
    painter->drawPath(shape());
//    painter->drawImage(QPoint(0,0),image/*.scaled(sirka,vyska)*/);
}
