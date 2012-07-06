#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "model/bird.h"
#include "model/map.h"
#include "model/obstacle.h"

#include "view/birddrawer.h"
#include "view/mapdrawer.h"
#include "view/obstacledrawer.h"

#include "model/vector2d.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_scene(new QGraphicsScene(this)),
    m_timer(new QTimer(this)),
    m_map(NULL),
    m_mapDrawer(NULL)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(m_scene);

    steering_behaviors::BirdVector birds;
    for (int i = 0; i < 1; i++) {
        steering_behaviors::Bird bird(Vector2D((float) (rand() % 10),
                                               (float) (rand() % 10)),
                                      Vector2D((float) (rand() % 5),
                                               (float) (rand() % 5)));
        birds.append(bird);
    }

    steering_behaviors::ObstacleVector obstacles;
    steering_behaviors::Obstacle u(Vector2D (0.f, 0.f),
                                   Vector2D(500.f, 0.f));

    steering_behaviors::Obstacle l(Vector2D (0.f, 0.f),
                                   Vector2D(0.f, 500.f));

    steering_behaviors::Obstacle r(Vector2D (500.f, 0.f),
                                   Vector2D(0.f, 500.f));

    steering_behaviors::Obstacle d(Vector2D (0.f, 500.f),
                                   Vector2D(500.f, 0.f));

    obstacles.append(u);
    obstacles.append(l);
    obstacles.append(r);
    obstacles.append(d);

    m_map = new steering_behaviors::Map(Vector2D(0.f, 0.f), Vector2D(100.f, 100.f), birds, obstacles);

    m_mapDrawer = new steering_behaviors::MapDrawer(*m_map);

    m_mapDrawer->draw(m_scene);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    m_timer->start(60/1000); // 60 frames per second
}

MainWindow::~MainWindow()
{
    m_timer->stop();
    disconnect(m_timer, SIGNAL(timeout()));
    delete m_timer;

    delete ui;

    delete m_scene;
    delete m_mapDrawer;
    delete m_map;
}

void MainWindow::birdCountUpdate(const int newValue) {

    // increase population
    for (int i = m_map->birds().size(); i < newValue; i++) {
        steering_behaviors::Bird bird(Vector2D((float) (rand() % 100),
                                               (float) (rand() % 100)),
                                      Vector2D((float) (rand() % 5),
                                               (float) (rand() % 5)));
        m_map->birds().append(bird);
    }

    // decrease population
    for (int i = newValue; i < m_map->birds().size(); i++) {
        m_map->birds().remove(i);
    }

}

void MainWindow::birdDown(void) {
    for (int i = 0; i < m_map->birds().size(); i++) {
        steering_behaviors::Bird & bird = m_map->birds()[i];
        Vector2D & position = bird.position();
        position = position.add(Vector2D(0.f, 10.f));
    }
}

void MainWindow::timerUpdate(void) {

    m_mapDrawer->draw(m_scene);

}
