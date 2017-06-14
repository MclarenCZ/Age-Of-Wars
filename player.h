#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>

class Player : public QGraphicsItem
{
public:
    Player(int type);
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

#endif // PLAYER_H
