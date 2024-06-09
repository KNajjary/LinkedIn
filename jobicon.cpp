#include "jobicon.h"
#include "jobui.h"
#include "ui_jobicon.h"

JobIcon::JobIcon(QString u,unsigned int n,QString pu,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JobIcon)
    ,job(new Job(u,n))
{
    ui->setupUi(this);
    PersonUsername=pu;
    //
    ui->label_Name->setText(job->GetName());
    ui->label_Company->setText(job->GetCompany());
    //
    QPixmap Im(job->GetProfile());
    unsigned int h = ui->label_Prof->height();
    unsigned int w=ui->label_Prof->width();
    ui->label_Prof->setPixmap(Im.scaled(w,h,Qt::KeepAspectRatioByExpanding));
}

JobIcon::~JobIcon()
{
    delete ui;
}

void JobIcon::on_pushButton_View_clicked()
{
    if(PersonUsername.isNull()){
        JobUi * j = new JobUi(job->GetUsername(),job->GetNumber());
        j->show();
    }
    else{
        JobUi * j = new JobUi(job->GetUsername(),job->GetNumber(),PersonUsername);
        j->show();
    }


    //this->close();
}
Job JobIcon::GetJob() const
{
    return *job;
}
