#include "prayer.h"
#include <QDebug>
#include <QKeyEvent>
#include <Bullet.h>
#include <Enemy.h>
#include <QDebug>
#include <QGraphicsScene>

Prayer::Prayer() {}


void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "El rectangulo sabe que presione una tecla";
    if (event -> key() == Qt::Key_Left){
        if (pos().x()>0){
            setPos(x()-10,y());
        }
    }
    else if (event -> key() == Qt::Key_Right){
        if (pos().x()+100 < 800){
            setPos(x()+10,y());
        }
    }
    else if (event -> key() == Qt::Key_Up){
        if (pos().x()+100 < 800){
            setPos(x(),y()-10);
        }
    }
    else if (event -> key() == Qt::Key_Down){
        if (pos().x()+100 < 800){
            setPos(x(),y()+10);
        }
    }
