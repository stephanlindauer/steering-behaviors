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

    rect = scene->addEllipse(10, 10, 100, 100, blackPen, redBrush);

    for (unsigned int i = 0; i < 25; i++) {
        const Vector2d position(rand()%scene->width(), rand()%scene->height());
        const Vector2d velocity(rand()%5, rand()%5);
        const Bird b(position, velocity);
        birds.append(b);
    }

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

}

void MainWindow::update() {
    scene->clear();

    QVector<Bird>::iterator current = birds.first();
    QVector<Bird>::const_iterator last = birds.last();

    {
        const Vector2d velocity(rand() % 5, rand() % 5);
        current->velocity(velocity);
        current->update();
        current->draw(scene);
        current++;

    } while (current != last);

}

MainWindow::~MainWindow()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()));
    delete timer;
    delete ui;
}
