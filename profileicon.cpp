#include "profileicon.h"
#include "company.h"
#include "mydatabase.h"
#include "person.h"
#include "ui_profileicon.h"

ProfileIcon::ProfileIcon(QString u,QString pu, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfileIcon)
{
    ui->setupUi(this);
    PersonUsername=pu;
    MyDatabase db;
    if(db.SelectWhere("Users","Username",u,"IsCompany",1).toInt() == 1)
        IsPerson=false;
    else IsPerson=true;

    //
    if(db.SelectWhere("Users","Username",PersonUsername,"IsCompany",1).toInt() == 1)
        IAmCompany=true;
    else IAmCompany=false;
    if(IAmCompany)
        ui->pushButton_ConFol->hide();
    //
    if(IsPerson){
        member = new Person(u);
        ui->label_Name->setText(member->GetFirstName()+" "+member->GetLastName());
        ui->label_Field->setText(member->GetCareer());

    }
    else {
        member = new Company(u);
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


}

ProfileIcon::~ProfileIcon()
{
    delete ui;
}
