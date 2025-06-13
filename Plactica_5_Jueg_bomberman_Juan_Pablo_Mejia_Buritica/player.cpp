#include "player.h"
#include "bomb.h"
#include "game.h"
#include "door.h"
#include "powerup.h"
#include <qgraphicsscene.h>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsScene>
#include <QGraphicsItem>


Player::Player() {
    setPixmap(QPixmap(":/image/player.png").scaled(40, 40));

    bombsound = new QMediaPlayer();
    bomboutput = new QAudioOutput();
    bombsound->setAudioOutput(bomboutput);
    bombsound->setSource(QUrl("qrc:/sound/place_bomb.mp3"));

    powerUpsound = new QMediaPlayer();
    powerUpoutput = new QAudioOutput();
    powerUpsound->setAudioOutput(powerUpoutput);
    powerUpsound->setSource(QUrl("qrc:/sound/powerUp.mp3"));
}

void Player::keyPressEvent(QKeyEvent* event) {
    int step = 40;
    QPointF newPos = pos();

    switch (event->key()) {
    case Qt::Key_W: newPos.ry() -= step; setPixmap(QPixmap(":/image/playerU.png").scaled(40, 40)); break;
    case Qt::Key_S: newPos.ry() += step; setPixmap(QPixmap(":/image/player.png").scaled(40, 40)); break;
    case Qt::Key_A: newPos.rx() -= step; setPixmap(QPixmap(":/image/playerL.png").scaled(40, 40)); break;
    case Qt::Key_D: newPos.rx() += step; setPixmap(QPixmap(":/image/playerR.png").scaled(40, 40)); break;
    case Qt::Key_Space: {
        bombsound->play();
        Bomb* bomb = new Bomb(scene(), pos(), bombRange);
        break;
        }
    }

    QList<QGraphicsItem*> itemsAtNewPos = scene()->items(QRectF(newPos, QSizeF(40, 40)));
    for (QGraphicsItem* item : std::as_const(itemsAtNewPos)) {
        if (item == this) continue;

        if (PowerUp* power = dynamic_cast<PowerUp*>(item)) {
            powerUpsound->play();
            scene()->removeItem(power);
            delete power;
            increaseBombRange();
            continue;
        }
        if (Door* door = dynamic_cast<Door*>(item)) {
            scene()->removeItem(door);
            delete door;

            Game* game = dynamic_cast<Game*>(scene()->views().first());
            if (game) {
                game->winGame();
            }
            return;
        }
        if (dynamic_cast<QGraphicsPixmapItem*>(item)) {
            return;
        }
    }
    setPos(newPos);
}

void Player::increaseBombRange() {
    bombRange++;
}
