#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow2.h"
#include "mainwindow3.h"
#include "mainwindow4.h"
#include<QString>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow2 *m2;
    QSqlDatabase mydb;
    MainWindow *firstWindow;
    MainWindow4 *gameWindow;

};

#endif // MAINWINDOW_H
