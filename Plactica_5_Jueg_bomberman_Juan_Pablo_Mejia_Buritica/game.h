#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "Player.h"

class Game : public QGraphicsView {
public:
    Game(QWidget* parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;
    void reduceLife();
    int getLives() const;
    Player* getPlayer() const { return player;}
    void addScore(int points);
    void winGame();
private:
    int lives = 5;
    QGraphicsScene* scene;
    Player* player;
    void setupMap();
    void restartGame();
    void endGame();

    QGraphicsTextItem* lifeText;
    void updateHUD();
    int score = 0;
    QGraphicsTextItem* scoreText;

    QMediaPlayer * lifeDownsound;
    QAudioOutput * lifeDownoutput;

    QMediaPlayer * music;
    QAudioOutput * musicoutput;

    QMediaPlayer * winsound;
    QAudioOutput * winoutput;

    void onMusicFinished();
};

#endif // GAME_H
