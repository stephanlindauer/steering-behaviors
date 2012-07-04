#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_scene(new QGraphicsScene(this)),
    m_timer(new QTimer(this))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(m_scene);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
    m_timer->start(1000);
}

MainWindow::~MainWindow()
{
    m_timer->stop();
    disconnect(m_timer, SIGNAL(timeout()));
    delete m_timer;

    delete ui;

    delete m_scene;
}

void MainWindow::update(void) {
}
