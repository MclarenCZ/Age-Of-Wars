#ifndef BASE_H
#define BASE_H
#include <QGraphicsItem>

class Base : public QGraphicsItem
{
public:
    Base();
    QRectF boundingRect() const;
    int sirka = 100;
    int vyska = 100;
    QString file = "missing.png";

protected:
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
};

#endif // BASE_H
