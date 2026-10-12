#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), game(Load::LoadMap("E:/ADRIEN_2026/C++/Sokoban/maps/map_test.txt"))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* e){   //affiche a l'ecran tt les choses a afficher
    QWidget::paintEvent(e);
    QPainter painter(this);

    game.Show(&painter, width(),height());
}

void MainWindow::keyPressEvent(QKeyEvent * event){   //event loop, cest un peu la boucle du jeu, on detecte les touche utiliser par le joueur afin deffectuer les action quil souhaite realiser
    switch (event->key()){
    case Qt::Key_Left : game.map.movePlayer(Direction::Left);
        break;
    case Qt::Key_Right : game.map.movePlayer(Direction::Right);
        break;
    case Qt::Key_Up : game.map.movePlayer(Direction::Up);
        break;
    case Qt::Key_Down : game.map.movePlayer(Direction::Down);
        break;
    default:
        break;
    }

    this->repaint();
}
