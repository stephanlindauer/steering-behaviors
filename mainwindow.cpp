#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bird.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);

    rect = scene->addEllipse(10,10,100,100, blackPen, redBrush);

    Bird birdybird = Bird(10,10,10,10);
    birdybird.draw(scene);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(foo()));
    timer->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}
