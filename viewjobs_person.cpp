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
    ui->pushButton_showAll->hide();
    ui->pushButton_next->hide();
    ui->pushButton_prev->hide();
    JobLimit =4;
    unsigned int i;
    MyDatabase db;
    Career=db.SelectWhere("Users","Username",PersonUsername,"Career",1);
    if(Career.isEmpty())
        ui->label_Career->setText("Your Career");
    else
        ui->label_Career->setText(Career);

    //--------------------------
    JobNum= db.GetNumberOfRows(JobsTable);
    qDebug()<<JobNum;
    for(i=1;i<=JobNum;i++){
        QString Username;
        unsigned int Number;
        //if( db.Select(JobsTable,"Number",i).isEmpty())break;
        Username=db.Select(JobsTable,"Username",i);
        Number=db.Select(JobsTable,"Number",i).toInt();
        JobIcon * job=new JobIcon(Username,Number,PersonUsername);
        if(job->GetJob().GetField() != Career){
            //i--;
            continue;
        }
        //job->show();
        /*qDebug()<<*/ ui->stackedWidget->addWidget(job);
        ui->label_NoJob->hide();
        ui->pushButton_next->show();
        ui->pushButton_prev->show();

    }
}

ViewJobs_Person::~ViewJobs_Person()
{
    delete ui;
}

void ViewJobs_Person::on_pushButton_next_clicked()
{
    int i=ui->stackedWidget->currentIndex();
    if(i == JobLimit)
    {
        if(i < JobNum -1)ui->pushButton_showAll->show();
        return;
    }
    i++;
    ui->stackedWidget->setCurrentIndex(i);
}


void ViewJobs_Person::on_pushButton_prev_clicked()
{
    int i=ui->stackedWidget->currentIndex();
    i--;
    ui->stackedWidget->setCurrentIndex(i);
}


void ViewJobs_Person::on_pushButton_showAll_clicked()
{
    JobLimit = JobNum-1;
    ui->pushButton_showAll->hide();
}

