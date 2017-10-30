#ifndef MAINWINDOW4_H
#define MAINWINDOW4_H

#include <QMainWindow>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QtSql>

namespace Ui {
class MainWindow4;
}

class MainWindow4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow4(QWidget *parent = 0);
    ~MainWindow4();

private:
    Ui::MainWindow4 *ui;
public:
    QString getuser;
    QString question,answer;
    QString response;
    QString ans;
    QFile q,a;
    QTextStream in,out;
    QString l;
private slots:
    void on_submit_clicked();
    void on_start_clicked();
public:
    void displayUser();
    void cricketLast();
    void moviesLast();
    void companiesLast();
    void updateLevel();
};

#endif // MAINWINDOW4_H
