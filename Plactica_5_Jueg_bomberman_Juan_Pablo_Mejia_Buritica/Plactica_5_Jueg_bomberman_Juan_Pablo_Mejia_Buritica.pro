QT       += core gui
QT += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomb.cpp \
    door.cpp \
    enemy.cpp \
    game.cpp \
    main.cpp \
    player.cpp \
    powerup.cpp \
    wall.cpp

HEADERS += \
    bomb.h \
    door.h \
    enemy.h \
    game.h \
    player.h \
    powerup.h \
    wall.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/FondoB.png

RESOURCES += \
    resources.qrc
