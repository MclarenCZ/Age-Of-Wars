#include "camera.h"

Camera::Camera()
{
}

QPointF Camera::getPosition()
{
    return this->pos;
}

void Camera::setPosition(float x, float y)
{
    this->pos = QPointF(x, y);
    this->checkBorders();
}

void Camera::setPosition(QPointF position)
{
    this->pos = position;
    this->checkBorders();
}

void Camera::move(float x, float y)
{
    this->pos += QPointF(x, y);
    this->checkBorders();
}

void Camera::move(QPointF move)
{
    this->pos += move;
    this->checkBorders();
}

void Camera::checkBorders()
{
    int left = 1100;//upravit
    int top = 200;//upravit

    if(pos.rx() < 0) pos.setX(0);
    if(pos.ry() < 0) pos.setY(0);
    if(pos.rx() > left) pos.setX(left);
    if(pos.ry() > top) pos.setY(top);
}
