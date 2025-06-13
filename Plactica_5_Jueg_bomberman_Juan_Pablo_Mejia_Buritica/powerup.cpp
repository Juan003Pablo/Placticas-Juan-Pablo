#include "powerup.h"
#include <QPixmap>

PowerUp::PowerUp() {
    setPixmap(QPixmap(":/image/powerup.png").scaled(40, 40));
}
