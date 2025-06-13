#include "bomb.h"
#include "game.h"
#include "player.h"
#include "wall.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

Bomb::Bomb(QGraphicsScene* scene, QPointF position, int range)
    : scene(scene), range(range) {
    setPixmap(QPixmap(":/image/bomb.png").scaled(40, 40));
    setPos(position);
    scene->addItem(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bomb::explode);
    timer->start(2000);

    bombsound = new QMediaPlayer();
    bomboutput = new QAudioOutput();
    bombsound->setAudioOutput(bomboutput);
    bombsound->setSource(QUrl("qrc:/sound/bomb_explodes.mp3"));

    enemydiesound = new QMediaPlayer();
    enemydieoutput = new QAudioOutput();
    enemydiesound->setAudioOutput(enemydieoutput);
    enemydiesound->setSource(QUrl("qrc:/sound/enemy_die.mp3"));
}

void Bomb::explode() {
    scene->removeItem(this);
    deleteLater();

    const int tileSize = 40;
    QList<QPointF> explosionPositions;
    explosionPositions << pos();

    bombsound->play();
    for (int i = 1; i < range; ++i) {
        explosionPositions << QPointF(pos().x() + i * tileSize, pos().y());
        explosionPositions << QPointF(pos().x() - i * tileSize, pos().y());
        explosionPositions << QPointF(pos().x(), pos().y() + i * tileSize);
        explosionPositions << QPointF(pos().x(), pos().y() - i * tileSize);
    }


    for (const QPointF& p : explosionPositions) {
        QList<QGraphicsItem*> items = scene->items(QRectF(p, QSizeF(40, 40)));
        for (QGraphicsItem* item : items) {
            if (dynamic_cast<Brick*>(item)) {
                scene->removeItem(item);
                delete item;
            } else if (Enemy* enemy = dynamic_cast<Enemy*>(item)) {
                enemydiesound->play();
                scene->removeItem(enemy);
                delete enemy;
                if (Game* game = dynamic_cast<Game*>(scene->views().first())) {
                    game->addScore(100);
                }
                qDebug() << "Enemigo eliminado";
            } else if (Player* player = dynamic_cast<Player*>(item)) {
                Game* game = dynamic_cast<Game*>(scene->views().first());
                if (game) {
                    game->reduceLife();
                }
            }
        }

        QGraphicsPixmapItem* flame = new QGraphicsPixmapItem(QPixmap(":/image/flame.png").scaled(40, 40));
        flame->setPos(p);
        flame->setZValue(-1);
        scene->addItem(flame);

        QTimer::singleShot(500, [scene = this->scene, flame]() {
            scene->removeItem(flame);
            delete flame;
        });
    }
}
