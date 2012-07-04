#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

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
    QGraphicsScene * m_scene;
    QTimer * m_timer;
};

#endif // MAINWINDOW_H
