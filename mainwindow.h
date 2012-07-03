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
    explicit MainWindow(QWidget *parent = 0) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        timer(new QTimer(this))
    {
        ui->setupUi(this);
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);

        for (unsigned int i = 0; i < 5; i++) {
            Bird b;
            birds.append(b);
        }

        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);

    }

    ~MainWindow() {
        timer->stop();
        disconnect(timer, SIGNAL(timeout()));
        delete timer;
        delete ui;
    }

public slots:

    void update(void) {

    }
    
private:
    Ui::MainWindow * ui;
    QGraphicsScene * scene;
    QTimer * timer;
    QVector<Bird> birds;

};

#endif // MAINWINDOW_H



