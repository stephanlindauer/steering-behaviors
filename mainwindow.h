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
    void timerUpdate(void);
    void setRandomSource(const bool useRandomOrg);

protected:

    int getSceneWidth(void);
    int getSceneHeight(void);

    
private:
    Ui::MainWindow * ui;
    QGraphicsScene * m_scene;
    QTimer * m_timer;

    steering_behaviors::Map * m_map;
    steering_behaviors::MapDrawer * m_mapDrawer;

    void addBird(void);
};

#endif // MAINWINDOW_H
