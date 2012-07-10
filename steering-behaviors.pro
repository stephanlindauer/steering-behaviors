#-------------------------------------------------
#
# Project created by QtCreator 2012-07-04T02:56:37
#
#-------------------------------------------------

QT       += core gui

TARGET = steering-behaviors
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model/random.cpp

HEADERS  += mainwindow.h \
    model/object.h \
    model/vector2d.h \
    model/bird.h \
    model/obstacle.h \
    model/map.h \
    model/area.h \
    view/drawer.h \
    view/mapdrawer.h \
    view/birddrawer.h \
    view/obstacledrawer.h \
    view/qtutil.h \
    model/vectorutil.h \
    control/brain.h \
    model/strategy.h \
    model/strategies/flee.h \
    model/strategies/follow.h \
    model/strategies/base.h \
    model/random.h

FORMS    += mainwindow.ui
