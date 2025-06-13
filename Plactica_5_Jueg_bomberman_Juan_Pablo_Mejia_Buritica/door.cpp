#include "door.h"
#include "qpixmap.h"

Door::Door() {
    setPixmap(QPixmap(":/image/door.png").scaled(40, 40));
}
