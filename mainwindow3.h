#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include "mainwindow4.h"
#include<QString>
#include<QFile>

namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = 0);
    ~MainWindow3();

private slots:
    void on_sports_clicked();

    void on_movies_clicked();

    void on_companies_clicked();

    void on_india_clicked();

    void on_logout_clicked();

    void on_leaderboard_clicked();
public:
    void displayUser();
private:
    MainWindow4 *gameWindow;
public:
    QString getuser;

private:
    Ui::MainWindow3 *ui;
};

#endif // MAINWINDOW3_H
