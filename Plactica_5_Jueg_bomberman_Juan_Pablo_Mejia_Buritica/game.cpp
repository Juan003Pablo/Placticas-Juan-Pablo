#include "game.h"
#include "door.h"
#include "enemy.h"
#include "powerup.h"
#include "wall.h"
#include "qgraphicsitem.h"

Game::Game(QWidget* parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
    setFixedSize(1300, 700);
    scene->setSceneRect(0, 0, 1200, 600);

    scene->setBackgroundBrush(QBrush(QColor(16, 120, 48)));
    setupMap();

    player = new Player();
    player->setPos(40, 40);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    lifeText = new QGraphicsTextItem();
    lifeText->setDefaultTextColor(Qt::white);
    lifeText->setFont(QFont("Terminal", 16));
    lifeText->setZValue(10);
    lifeText->setPos(10, -30);
    scene->addItem(lifeText);

    scoreText = new QGraphicsTextItem();
    scoreText->setDefaultTextColor(Qt::white);
    scoreText->setFont(QFont("Terminal", 16));
    scoreText->setZValue(10);
    scoreText->setPos(100, -30);
    scene->addItem(scoreText);

    updateHUD();

    lifeDownsound = new QMediaPlayer();
    lifeDownoutput = new QAudioOutput();  // Crear la salida de audio
    lifeDownsound->setAudioOutput(lifeDownoutput);
    lifeDownsound->setSource(QUrl("qrc:/sound/life_Down.mp3"));

    winsound = new QMediaPlayer();
    winoutput = new QAudioOutput();
    winsound->setAudioOutput(winoutput);
    winsound->setSource(QUrl("qrc:/sound/StageClear.mp3"));

    music = new QMediaPlayer();
    musicoutput = new QAudioOutput();
    music->setAudioOutput(musicoutput);
    music->setSource(QUrl("qrc:/sound/Bomberman_background.mp3"));

    music->play();
    musicoutput->setVolume(0.5);

    connect(music, &QMediaPlayer::mediaStatusChanged, this, &Game::onMusicFinished);
}

int Game::getLives() const {
    return lives;
}

void Game::setupMap() {
    const int tileSize = 40;
    int conta = rand() % 15 + 1;
    for (int x = 0; x < 1200; x += tileSize) {
        for (int y = 0; y < 600; y += tileSize) {
            if (x == 0 || y == 0 || x == 1160 || y == 560 || (x % 80 == 0 && y % 80 == 0)) {
                Wall* wall = new Wall();
                wall->setPos(x, y);
                scene->addItem(wall);
            } else if (rand() % 7 == 0) {
                Brick* brick = new Brick();
                brick->setPos(x, y);
                scene->addItem(brick);
                if (conta == 1) {
                    Door* door = new Door();
                    door->setPos(x, y);
                    //door->setZValue(-1);
                    scene->addItem(door);
                    conta = 0;
                } else {conta--;}
            } else if (rand() % 20 == 0) {
                Enemy* enemy = new Enemy(scene);
                enemy->setPos(x, y);
                scene->addItem(enemy);
            } else if (rand() % 80 == 0) {
                PowerUp* powerup = new PowerUp();
                powerup->setPos(x, y);
                scene->addItem(powerup);
            }
        }
    }



}

void Game::keyPressEvent(QKeyEvent* event) {
    player->keyPressEvent(event);
}

void Game::updateHUD() {
    lifeText->setPlainText(QString("Vidas: %1").arg(lives));
    scoreText->setPlainText(QString("Puntaje: %1").arg(score));
}

void Game::addScore(int points) {
    score += points;
    updateHUD();
}
void Game::restartGame() {
    scene->clear();

    lives = 5;
    score = 0;

    player = new Player();
    player->setPos(40, 40);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    lifeText = new QGraphicsTextItem();
    lifeText->setDefaultTextColor(Qt::white);
    lifeText->setFont(QFont("Terminal", 16));
    lifeText->setZValue(10);
    lifeText->setPos(10, -30);
    scene->addItem(lifeText);

    scoreText = new QGraphicsTextItem();
    scoreText->setDefaultTextColor(Qt::white);
    scoreText->setFont(QFont("Terminal", 16));
    scoreText->setZValue(10);
    scoreText->setPos(100, -30);
    scene->addItem(scoreText);

    setupMap();

    updateHUD();
}

void Game::winGame() {
    music->stop();
    winsound->play();
    QGraphicsTextItem* winText = new QGraphicsTextItem("¡Ganaste!");
    winText->setDefaultTextColor(Qt::green);
    winText->setFont(QFont("Terminal", 32));
    winText->setZValue(20);
    winText->setPos(width()/2 - 100, height()/2 - 50);
    scene->addItem(winText);

    QTimer::singleShot(3000, this, [this]() {
        music->setPosition(0);
        music->play();
        restartGame();
    });
}

void Game::reduceLife() {
    lifeDownsound->play();
    lives--;
    qDebug() << "Vida perdida, vidas restantes:" << lives;
    updateHUD();

    if (lives <= 0) {
        restartGame();
    } else {
        player->setPos(40, 40);
    }
}

void Game::onMusicFinished() {
    if (music->mediaStatus() == QMediaPlayer::EndOfMedia) {   
        music->setPosition(0);
        music->play();
    }
}
