#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QGraphicsItem>

class Background : public QGraphicsItem
{
public:
    Background(QString filename, int sirka, int vyska);
    QRectF boundingRect() const;
    int sirka = 100;
    int vyska = 100;
    QString file = "missing.png";

protected:
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
};

#endif // BACKGROUND_H
