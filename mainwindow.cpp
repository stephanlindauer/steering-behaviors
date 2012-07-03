#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bird.h"
#include "vector2d.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);

    //rect = scene->addEllipse(10, 10, 100, 100, blackPen, redBrush);

    for (unsigned int i = 0; i < 5; i++) {
        Bird b;
        birds.append(b);
    }

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

}

void MainWindow::update() {
    scene->clear();
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    scene->addRect(0, 0, scene->width(), scene->height(), blackPen);

    Bird::STAGE_WIDTH = (unsigned int) scene->width();
    Bird::STAGE_HEIGHT = (unsigned int) scene->height();

    for (int i = 0; i < birds.size(); i++) {
        birds[i].update();
        birds[i].draw(scene);
    }

}

MainWindow::~MainWindow()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()));
    delete timer;
    delete ui;
}
