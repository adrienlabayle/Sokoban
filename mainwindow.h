#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        void paintEvent(QPaintEvent* e);
        void keyPressEvent(QKeyEvent * event);

        void showMenu();
        void showGame();

    private slots:
        void on_menuPlayButton_clicked();

    private:
        Ui::MainWindow *ui;
        Game game;

        QPixmap menuBackground;

};
#endif // MAINWINDOW_H
