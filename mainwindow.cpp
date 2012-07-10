#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "model/bird.h"
#include "model/map.h"
#include "model/obstacle.h"
#include "model/strategies/flee.h"
#include "model/strategies/follow.h"
#include "model/vector2d.h"
#include "model/random.h"

#include "view/birddrawer.h"
#include "view/mapdrawer.h"
#include "view/obstacledrawer.h"

#include "control/brain.h"

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

//    ui->graphicsView->geometry()
    m_scene->setSceneRect(0, 0, 500, 500);

    steering_behaviors::BirdVector birds;

    steering_behaviors::ObstacleVector obstacles;
    for (int i = 0; i < 500; i+=5) {
        steering_behaviors::Obstacle up(Vector2D ((float) i, 0.f),
                                        Vector2D(5.f, 5.f));
        obstacles.append(up);

        steering_behaviors::Obstacle left(Vector2D (0.f, (float) i),
                                          Vector2D(5.f, 5.f));
        obstacles.append(left);

        steering_behaviors::Obstacle right(Vector2D (495.f, (float) i),
                                           Vector2D(5.f, 5.f));
        obstacles.append(right);

        steering_behaviors::Obstacle down(Vector2D ((float) i, 495.f),
                                          Vector2D(5.f, 5.f));
        obstacles.append(down);
    }

    obstacles.append(steering_behaviors::Obstacle(Vector2D(245.f, 245.f), Vector2D(10.f, 10.f)));

    m_map = new steering_behaviors::Map(Vector2D(0.f, 0.f), Vector2D(100.f, 100.f), birds, obstacles);

    birdCountUpdate(ui->birdCountSpinBox->value());

    m_mapDrawer = new steering_behaviors::MapDrawer(*m_map);

    m_mapDrawer->draw(m_scene);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    m_timer->start((int) (1000.f/60.f)); // 60 frames per second
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
        addBird();
    }

    // decrease population
    for (int i = newValue; i < m_map->birds().size(); i++) {
        m_map->birds().remove(i);
    }

}

void MainWindow::timerUpdate(void) {

    if (ui->runBox->isChecked())
        steering_behaviors::Brain::process(ui->sightBoxes->isChecked(), m_scene, *m_map, *m_mapDrawer);

    m_mapDrawer->draw(m_scene);

}

void MainWindow::setRandomSource(const bool useRandomOrg) {
    if (useRandomOrg)
        steering_behaviors::Random::setRandomOrg();
    else
        steering_behaviors::Random::setInternal();
}

int MainWindow::getSceneWidth(void) {
    return (int) (m_scene->width() - steering_behaviors::BirdDrawer::WIDTH);
}

int MainWindow::getSceneHeight(void) {
    return (int) (m_scene->height() - steering_behaviors::BirdDrawer::HEIGHT);
}

void MainWindow::addBird(void) {
    steering_behaviors::Bird bird(Vector2D((float) (steering_behaviors::Random::random(getSceneWidth())),
                                           (float) (steering_behaviors::Random::random(getSceneHeight()))));
    bird.add(new steering_behaviors::Flee(10));
    bird.add(new steering_behaviors::Follow(99));
    m_map->birds().append(bird);
}
