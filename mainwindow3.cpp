#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include "mainwindow4.h"
#include "mainwindow.h"
#include<QString>
#include<QFile>

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);

}

MainWindow3::~MainWindow3()
{
    delete ui;
}

void MainWindow3::displayUser()
{
     ui->user_key->setText(getuser);
}

void MainWindow3::on_sports_clicked()
{
    gameWindow=new MainWindow4;
    gameWindow->question="sports.txt";
    gameWindow->answer="sports_ans.txt";
    gameWindow->getuser=getuser;
    gameWindow->cricketLast();
    gameWindow->displayUser();

    hide();
    gameWindow->show();
}

void MainWindow3::on_movies_clicked()
{
    gameWindow=new MainWindow4;
    gameWindow->question="movies.txt";
    gameWindow->answer="movies_ans.txt";
    gameWindow->getuser=getuser;
    gameWindow->moviesLast();
    gameWindow->displayUser();

    hide();
    gameWindow->show();

}

void MainWindow3::on_companies_clicked()
{
    gameWindow=new MainWindow4;
    gameWindow->question="companies.txt";
    gameWindow->answer="companies_ans.txt";
    gameWindow->getuser=getuser;
    gameWindow->companiesLast();
    gameWindow->displayUser();

    hide();
    gameWindow->show();

}

void MainWindow3::on_india_clicked()
{
    gameWindow=new MainWindow4;
    gameWindow->question="india.txt";
    gameWindow->answer="india_ans.txt";
    gameWindow->getuser=getuser;
    gameWindow->displayUser();
    hide();
    gameWindow->show();

}

void MainWindow3::on_logout_clicked()
{
    MainWindow *loginPage;
    loginPage=new MainWindow;
    hide();
    loginPage->show();
}

void MainWindow3::on_leaderboard_clicked()
{

}
