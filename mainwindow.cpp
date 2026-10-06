#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_game(Load::LoadMap("E:/ADRIEN_2026/C++/Sokoban/map_test.txt"))
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

    m_game.Show(&painter, width(),height());
}
