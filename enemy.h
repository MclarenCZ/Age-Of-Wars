#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>

class Enemy : public QGraphicsItem
{
public:
    Enemy(int type);
    QRectF boundingRect() const;
    int speed = 2;
    int cooldown;
    int health;
    int damage;
    QString filename = "missing.png";
    bool isAttacking = false;
    int sirka = 20;
    int vyska = 30;

protected:
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QColor color = Qt::red;
};

#endif // ENEMY_H
