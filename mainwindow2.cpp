#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow3.h"
#include<QMessageBox>

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_pushButton_clicked()
{
    QString name,username,password;

    name=ui->lineEdit->text();
    username=ui->lineEdit_2->text();
    password=ui->lineEdit_3->text();

    QSqlQuery query;
    if(query.exec("select * from userdata where username='"+username+"' "))
    {
        int count=0;
        while(query.next())
        {
            count++;
        }
        if(count<1)
        {
            query.exec("insert into userdata values('"+username+"','"+password+"',0,0,0,0,0,0 )");
            QMessageBox::information(this,"CONGO","You are now a memeber of this legacy.See you on the leaderboard.");
            MainWindow3 *categoryWindow;
            categoryWindow=new MainWindow3;
            categoryWindow->getuser=username;
            categoryWindow->displayUser();
            hide();
            categoryWindow->show();
        }
        else
        {
            QMessageBox::information(this,"SORRY","Username already in use.Try another username.");
            m2=new MainWindow2;
            hide();
            m2->show();
        }
    }
}
