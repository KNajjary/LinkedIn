#include "mynetwork_company.h"
#include "mydatabase.h"
#include "profileicon.h"
#include "ui_mynetwork_company.h"

MyNetwork_Company::MyNetwork_Company(QString u,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyNetwork_Company)
{
    ui->setupUi(this);
    company= new Company(u);

    MyDatabase db;

    int i=db.GetNumberOfRows(company->GetFollowersTable());

    for(;i>0;i--)
    {
        ProfileIcon * p=new ProfileIcon(company->GetUsername(),company->GetFollower(i));
        //p->show();
        ui->stackedWidget_followers->addWidget(p);
    }
    //
    if(ui->stackedWidget_followers->currentIndex() != -1)
    {
        ui->label_NoFollower->hide();
    }
    else
    {
        ui->pushButton_next->hide();
        ui->pushButton_prev->hide();
    }
}

MyNetwork_Company::~MyNetwork_Company()
{
    delete ui;
}

void MyNetwork_Company::on_pushButton_next_clicked()
{
    int i=ui->stackedWidget_followers->currentIndex();
    i++;
    ui->stackedWidget_followers->setCurrentIndex(i);
}


void MyNetwork_Company::on_pushButton_prev_clicked()
{
    int i=ui->stackedWidget_followers->currentIndex();
    i--;
    ui->stackedWidget_followers->setCurrentIndex(i);
}

