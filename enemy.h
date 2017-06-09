#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>

class Enemy : public QGraphicsItem
{
public:
    Enemy();
    QRectF boundingRect() const;
    int speed = 2;

protected:
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int sirka = 20;
    int vyska = 30;
};

#endif // ENEMY_H
