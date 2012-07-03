#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <stdio.h>
#include <bird.h>

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

    void update(void);
    
private:
    Ui::MainWindow * ui;
    QGraphicsScene * scene;
    QTimer * timer;
    QVector<Bird> birds;

};

#endif // MAINWINDOW_H



