#include "wall.h"
#include <QPixmap>

Wall::Wall() {
    setPixmap(QPixmap(":/image/wall.png").scaled(40, 40));
}

Brick::Brick() {
    setPixmap(QPixmap(":/image/brick.png").scaled(40, 40));
}
