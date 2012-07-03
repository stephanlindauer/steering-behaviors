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

    for (unsigned int i = 0; i < 25; i++) {
        const int x = rand() % 100;
        const int y = rand() % 100;
        const Vector2D position((float) x, (float) y);
        const Vector2D velocity(rand() % 5, rand() % 5);
        Bird b(position, velocity);
        b.draw(scene);
        birds.append(b);
    }

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

}

void MainWindow::update() {
    scene->clear();

    foreach (Bird bird, birds) {
        const Vector2D velocity(rand() % 5, rand() % 5);
        bird.velocity(velocity);
        bird.update();
        bird.draw(scene);
    }

}

MainWindow::~MainWindow()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()));
    delete timer;
    delete ui;
}
