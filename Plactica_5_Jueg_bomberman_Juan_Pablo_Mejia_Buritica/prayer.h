#ifndef PRAYER_H
#define PRAYER_H

#include <QGraphicsRectItem>
#include <QObject>

class Player:public QObject,public QGraphicsRectItem{
    Q_OBJECT;
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // PRAYER_H
