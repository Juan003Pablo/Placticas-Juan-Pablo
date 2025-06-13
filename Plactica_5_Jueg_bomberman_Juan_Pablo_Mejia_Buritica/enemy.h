#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsScene* scene);
    void move();

private:
    QTimer* moveTimer;
    QGraphicsScene* scene;
    int direction;
    bool canMoveTo(QPointF pos);
    void playerAttack(QPointF pos);
};

#endif // ENEMY_H
