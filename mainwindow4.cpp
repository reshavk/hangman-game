#include "mainwindow4.h"
#include "ui_mainwindow4.h"
#include<QMessageBox>
#include<QString>
#include<QFile>
#include<QPixmap>
#include<QTime>

MainWindow4::MainWindow4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow4)
{
    ui->setupUi(this);

    QPixmap pix("primary.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

MainWindow4::~MainWindow4()
{
    delete ui;
}

int flag=1,attempts=0,counter=0,level;


void MainWindow4::displayUser()
{
    ui->user_key->setText(getuser);
    ui->level->setText(l);
}

int category;
void MainWindow4::cricketLast(){
    category=1;
    QSqlQuery q;
    if(q.exec(" select * from userdata where username='"+getuser+"' "))
    {
        while(q.next()){
            level=q.value(5).toInt();
            l=QString::number(level);
        }
    }
}
void MainWindow4::moviesLast(){
    category=2;
    QSqlQuery q;
    if(q.exec(" select * from userdata where username='"+getuser+"' "))
    {
        while(q.next()){
            level=q.value(6).toInt();
            l=QString::number(level);
        }
    }
}
void MainWindow4::companiesLast(){
    category=3;
    QSqlQuery q;
    if(q.exec(" select * from userdata where username='"+getuser+"' "))
    {
        while(q.next()){
            level=q.value(7).toInt();
            l=QString::number(level);
        }
    }
}
void MainWindow4::updateLevel(){
    if(category==1){
        QSqlQuery q;
        q.exec("update userdata set cricket_last=level where username='"+getuser+"' ");
    }
    else if(category==2){
        QSqlQuery q;
        q.exec("update userdata set movie_last=level where username='"+getuser+"' ");
    }
    else{
        QSqlQuery q;
        q.exec("update userdata set company_last=level where username='"+getuser+"' ");
    }
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(3);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void MainWindow4::on_submit_clicked()
{
    response=ui->lineEdit->text();

       if(ans!=response)
       {
           flag=0;
           attempts++;
           //QMessageBox::warning(this,"INCORRECT","You entered an incorrect response");
           QPixmap pix("wrong.jpg");
           int w = ui->label_pic->width();
           int h = ui->label_pic->height();
           ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
       }
       else
       {
           flag=1;
           attempts=0;
           //QMessageBox::information(this,"CORRECT","You are absolutely right..!!!");
           QPixmap pix("primary.jpg");
           int w = ui->label_pic->width();
           int h = ui->label_pic->height();
           ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
           on_start_clicked();
       }

       if(attempts==3)
       {
           updateLevel();
           //QMessageBox::warning(this,"GAMEOVER","You have used your 3 attempts");
           QPixmap pix("hanged.jpg");
           int w = ui->label_pic->width();
           int h = ui->label_pic->height();
           ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
           delay();

           QMessageBox::warning(this,"GAMEOVER","You have used your 3 attempts");


       }

}

void MainWindow4::on_start_clicked()
{
    if(flag==1)
    {

        level++;
        QFile q(question);
        q.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream in(&q);

        QFile a(answer);
        a.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream out(&a);
        int i=0;
        QString line;
        while(i!=level)
        {
            line=in.readLine();
            ans=out.readLine();
            i++;
        }
        ui->textBrowser->setText(line);
        ui->lineEdit->setText("");
    }
    else
         QMessageBox::warning(this,"IMPOSSIBLE","You have not answered previous question");

}
