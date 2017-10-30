#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow3.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("userdata.db");

    if(mydb.open())
        ui->label_4->setText("Connected to Database Successfully");
    else if(!mydb.open())
        ui->label_4->setText("Unable to connect to Database");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    m2=new MainWindow2;
    hide();
    m2->show();

}

void MainWindow::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();

    QSqlQuery sql;
    if(sql.exec("select * from userdata where username='"+username+"' and password='"+password+"' "))
    {
        int count=0;
        while(sql.next())
        {
            count++;
        }
        if(count==1)
        {
            QMessageBox::information(this,"LOGIN SUCCESSFULL","Username and Password matched");
            MainWindow3 *categoryWindow;
            categoryWindow=new MainWindow3;
            categoryWindow->getuser=username;
            categoryWindow->displayUser();
            hide();
            categoryWindow->show();
        }
        else if(count<1)
        {
            QMessageBox::warning(this,"LOGIN FAILED","Check username and password");

        }
    }
}
