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

    void foo(void) {
scene->clear();
        for(int  i = 0; i < 20; i++)
        {
            int        randomPositionX = (rand() % (int)scene->width());
            int        randomPositionY = (rand() % (int)scene->height());
            int        randomVelocityX = (rand() % 5);
            int        randomVelocityY = (rand() % 5);

            Bird            bird = Bird(randomPositionX, randomPositionY, randomVelocityX, randomVelocityY);

            bird.draw(scene);
        }


        printf("hello world %d \n" , (rand() % (int)scene->width()));
        printf("hello world %d \n" , (rand() % (int)scene->height()));
        _flushall();

    }
    
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *rect;

};

#endif // MAINWINDOW_H



