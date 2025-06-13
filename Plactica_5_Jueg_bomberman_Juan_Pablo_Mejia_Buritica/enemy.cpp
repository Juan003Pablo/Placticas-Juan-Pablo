#include "enemy.h"
#include "game.h"
#include "player.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

Enemy::Enemy(QGraphicsScene* scene) : scene(scene) {
    setPixmap(QPixmap(":/image/enemy.png").scaled(40, 40));
    setZValue(1);

    direction = QRandomGenerator::global()->bounded(4);

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Enemy::move);
    moveTimer->start(500); // mover cada 500ms
}

bool Enemy::canMoveTo(QPointF pos) {
    QList<QGraphicsItem*> items = scene->items(QRectF(pos, QSizeF(40, 40)));
    for (QGraphicsItem* item : std::as_const(items)) {
        if (item != this && dynamic_cast<QGraphicsPixmapItem*>(item)) {
            return false;
        }
    }
    return true;
}

void Enemy::playerAttack(QPointF pos) {
    QList<QGraphicsItem*> items = scene->items(QRectF(pos, QSizeF(40, 40)));
    for (QGraphicsItem* item : std::as_const(items)) {
        if (Player* player = dynamic_cast<Player*>(item)) {
            Game* game = dynamic_cast<Game*>(scene->views().first());
            if (game) {
                game->reduceLife();
            }
            return;
        }
    }
}

void Enemy::move() {
    QPointF newPos = pos();
    int step = 40;

    switch (direction) {
    case 0: newPos.ry() -= step; break;
    case 1: newPos.rx() += step; break;
    case 2: newPos.ry() += step; break;
    case 3: newPos.rx() -= step; break;
    }

    if (canMoveTo(newPos)) {
        setPos(newPos);
    } else {
        playerAttack(newPos);
        direction = QRandomGenerator::global()->bounded(4);
    }
}
