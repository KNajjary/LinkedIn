#include "viewjobs_company.h"
#include "applylist.h"
#include "jobicon.h"
#include "mydatabase.h"
#include "newjob.h"
#include "ui_viewjobs_company.h"

ViewJobs_Company::ViewJobs_Company(QString u, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewJobs_Company)
{
    ui->setupUi(this);
    Username=u;
    //
    ShowJobs();
}

ViewJobs_Company::~ViewJobs_Company()
{
    delete ui;
}

void ViewJobs_Company::on_pushButton_NewJob_clicked()
{
    qDebug()<<JobCount;
    NewJob * newj=new NewJob(Username);
    newj->setWindowModality(Qt::ApplicationModal);
    newj->show();

    //##########problem-----------------jobs dont upload-----------------------
    //while(!newj->isHidden()){
    //    if(newj->isHidden())break;
    //}
    //MyDatabase db;
    //JobCount=db.SelectMax(Username+"_Jobs","Number").toInt();
    //int i=JobCount;
    //
    JobCount++;
    qDebug()<<JobCount;
}


void ViewJobs_Company::on_pushButton_nextJob_clicked()
{
    int i=ui->stackedWidget_Jobs->currentIndex();
    i++;
    ui->stackedWidget_Jobs->setCurrentIndex(i);
    ui->stackedWidget_applys->setCurrentIndex(i);
}


void ViewJobs_Company::on_pushButton_prevJob_clicked()
{
    int i=ui->stackedWidget_Jobs->currentIndex();
    i--;
    ui->stackedWidget_Jobs->setCurrentIndex(i);
    ui->stackedWidget_applys->setCurrentIndex(i);
}
void  ViewJobs_Company::ShowJobs()
{
    MyDatabase db;
    JobCount=db.SelectMax(Username+"_Jobs","Number").toInt();
    int i=JobCount;
    for(;i>0;i--){
        JobIcon * job=new JobIcon(Username,i);
        job->show();
        ui->stackedWidget_Jobs->addWidget(job);
        //
        ApplyList * list=new ApplyList(Username,i);
        list->show();
        ui->stackedWidget_applys->addWidget(list);
    }
    ui->stackedWidget_Jobs->setCurrentIndex(0);
    ui->stackedWidget_applys->setCurrentIndex(0);
}
