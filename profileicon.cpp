#include "profileicon.h"
#include "company.h"
#include "mydatabase.h"
#include "person.h"
#include "ui_profileicon.h"
#include "viewprofile.h"

ProfileIcon::ProfileIcon(QString myu,QString pu, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfileIcon)
{
    ui->setupUi(this);
    PersonUsername=pu;
    MyUsername=myu;
    MyDatabase db;
    if(db.SelectWhere("Users","Username",PersonUsername,"IsCompany",1).toInt() == 1)
        IsPerson=false;
    else IsPerson=true;

    //
    if(db.SelectWhere("Users","Username",MyUsername,"IsCompany",1).toInt() == 1)
        IAmCompany=true;
    else IAmCompany=false;
    if(IAmCompany)
    {

        ui->pushButton_ConFol->hide();
        me= new Company(MyUsername);
    }
    else
    {
        me= new Person(MyUsername);
    }

    //
    if(IsPerson){
        member = new Person(PersonUsername);
        ui->label_Name->setText(member->GetFirstName()+" "+member->GetLastName());
        ui->label_Field->setText(member->GetCareer());

    }
    else {
        member = new Company(PersonUsername);
        ui->label_Name->setText(static_cast <Company *>(member)->GetCompanyName());
        ui->label_Field->setText(member->GetCareer());
        ui->pushButton_ConFol->setText("Follow");

    }
    //
    QPixmap Im(member->GetPicture());
    int LabelW,LabelH;
    LabelH=ui->label_Picture->height();
    LabelW=ui->label_Picture->width();
    ui->label_Picture->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatioByExpanding));

    //
    ui->label_SentReq->hide();
    //
    if(! IAmCompany)
    {
        if(IsPerson )
        {
            if(static_cast <Person *>(me)->IsConnecting(PersonUsername))
                ui->pushButton_ConFol->hide();

        }
        else
        {
            if(static_cast <Person *>(me)->IsFollowing(PersonUsername))
                ui->pushButton_ConFol->hide();
        }
    }



}

ProfileIcon::~ProfileIcon()
{
    delete ui;
}

void ProfileIcon::on_pushButton_ViewProf_clicked()
{
    ViewProfile * v= new ViewProfile(PersonUsername);
    v->setWindowModality(Qt::ApplicationModal);
    v->show();
}


void ProfileIcon::on_pushButton_ConFol_clicked()
{
    if(IsPerson)
    {
        static_cast <Person *>(me)->RequestConnection(PersonUsername);
        ui->pushButton_ConFol->hide();
        ui->label_SentReq->show();

    }
    else
    {
        static_cast <Person *>(me)->FollowCompany(PersonUsername);
        ui->pushButton_ConFol->hide();
    }
}

