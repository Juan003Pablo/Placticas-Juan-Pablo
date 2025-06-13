#ifndef BOMB_H
#define BOMB_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

class Bomb : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bomb(QGraphicsScene* scene, QPointF position, int range = 2);

private slots:
    void explode();

private:
    QGraphicsScene* scene;
    int range;
    QTimer* timer;

    QMediaPlayer * bombsound;
    QAudioOutput * bomboutput;

    QMediaPlayer * enemydiesound;
    QAudioOutput * enemydieoutput;
};

#endif // BOMB_H
