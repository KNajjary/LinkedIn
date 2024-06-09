#include "viewjobs_person.h"
#include "jobicon.h"
#include "mydatabase.h"
#include "ui_viewjobs_person.h"

ViewJobs_Person::ViewJobs_Person(QString u ,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewJobs_Person)
    ,PersonUsername(u)
{
    ui->setupUi(this);
    unsigned int i;
    MyDatabase db;
    Career=db.SelectWhere("Users","Username",PersonUsername,"Career",1);
    ui->label_Career->setText(Career);
    for(i=1;i<=5;i++){
        QString Username;
        unsigned int Number;
        if( db.Select(JobsTable,"Number",i).isEmpty())break;
        Username=db.Select(JobsTable,"Username",i);
        Number=db.Select(JobsTable,"Number",i).toInt();
        JobIcon * job=new JobIcon(Username,Number,PersonUsername);
        if(job->GetJob().GetField() != Career){
            i--;
            continue;
        }
        job->show();
        qDebug()<< ui->stackedWidget->addWidget(job);

    }

}

ViewJobs_Person::~ViewJobs_Person()
{
    delete ui;
}

void ViewJobs_Person::on_pushButton_next_clicked()
{
    int i=ui->stackedWidget->currentIndex();
    i++;
    ui->stackedWidget->setCurrentIndex(i);
}


void ViewJobs_Person::on_pushButton_prev_clicked()
{
    int i=ui->stackedWidget->currentIndex();
    i--;
    ui->stackedWidget->setCurrentIndex(i);
}

