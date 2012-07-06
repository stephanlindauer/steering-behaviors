#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "model/map.h"
#include "view/mapdrawer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void birdCountUpdate(const int newValue);
    void birdDown(void);
    void timerUpdate(void);

    
private:
    Ui::MainWindow * ui;
    QGraphicsScene * m_scene;
    QTimer * m_timer;

    steering_behaviors::Map * m_map;
    steering_behaviors::MapDrawer * m_mapDrawer;
};

#endif // MAINWINDOW_H
