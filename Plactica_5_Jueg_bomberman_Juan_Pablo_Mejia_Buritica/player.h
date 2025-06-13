#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QAudioOutput>

class Player : public QGraphicsPixmapItem {
public:
    Player();
    void keyPressEvent(QKeyEvent* event) override;
    void increaseBombRange();
private:
    int bombRange = 2;

    QMediaPlayer * bombsound;
    QAudioOutput * bomboutput;

    QMediaPlayer * powerUpsound;
    QAudioOutput * powerUpoutput;
};

#endif // PLAYER_H
