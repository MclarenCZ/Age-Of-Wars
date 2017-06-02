#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>

class Player : public QGraphicsItem
{
public:
    Player(QString nazev,QColor barva,int sirka, int vyska);
    QRectF boundingRect() const;

protected:
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QColor barva;
    QString nazev;
    int sirka;
    int vyska;
};

#endif // PLAYER_H
