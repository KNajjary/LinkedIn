#include "me.h"
#include "completecompanyinfo.h"
#include "completeuserinfowindow.h"
#include "ui_me.h"
#include "mydatabase.h"
#include <QFileDialog>
Me::Me(QString u , QWidget *parent)
    : QMainWindow(parent)
    ,member(new Member(u))
    ,ui(new Ui::Me)
{
    ui->setupUi(this);
    Username=u;

    MyDatabase db;
    if(db.SelectWhere(member->GetTableName(),"Username",Username,"IsCompany",1).toInt())
        IsCompany=true;
    else IsCompany=false;

    //qDebug() << IsCompany;

    ShowAreYouCompanyBut();
    SetLabels();
    ShowImage();

}

Me::~Me()
{
    delete ui;
}
void Me::SetLabels()
{
    if(! member->GetUsername().isEmpty())
        ui->label_Username->setText(member->GetUsername());
    else ui->label_Username->setText("Username");
    if(member->GetFirstName().isEmpty() && member->GetLastName().isEmpty())
        ui->label_Name->setText("Name");
    else ui->label_Name->setText(member->GetFirstName()+" "+member->GetLastName());
    if(! member->GetAddress().isEmpty())
        ui->label_Address->setText(member->GetAddress());
    else ui->label_Address->setText("Address");

    if(! member->GetCareer().isEmpty())
        ui->label_Creer->setText(member->GetCareer());
    else if(IsCompany)ui->label_Creer->setText("Field");
    else ui->label_Creer->setText("Career");

    if(! member->GetPhone().isEmpty())
        ui->label_Phone->setText(member->GetPhone());
    else ui->label_Phone->setText("Phone");
    if(! member->GetEmail().isEmpty())
        ui->label_Email->setText(member->GetEmail());
    else ui->label_Email->setText("Email");

}

void Me::ShowAreYouCompanyBut()
{
    if(! IsCompany)ui->pushButton_AreYouCompany->show();
    else ui->pushButton_AreYouCompany->hide();

}
void Me::ShowImage()
{
    if(member->GetPicture().isEmpty()){
        ui->label_Picture->setText("Your profile picture");
        return;
    }

    QPixmap Im(member->GetPicture());
    int LabelW,LabelH;
    LabelH=ui->label_Picture->height();
    LabelW=ui->label_Picture->width();
    ui->label_Picture->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatio));

}

void Me::on_pushButton_clicked()
{
    QString ImageAddress = QFileDialog::getOpenFileName(
        this,
        "Choose picture",
        "D://Linked In//images",
        "Image File (*.png);;Image File (*.jpg);;");
    member->SetPicture(ImageAddress);
    ShowImage();

}


void Me::on_pushButton_EditProfile_clicked()
{
    if(IsCompany)
    {
        CompleteCompanyInfo * n= new CompleteCompanyInfo(member->GetUsername());
        n->show();
        this->close();
    }
    else
    {
        CompleteUserInfoWindow * n=new CompleteUserInfoWindow(member->GetUsername());
        n->Hide_pushButton_AreYouCompany();
        n->show();
        this->close();
        //if(n->)
    }

    //member = new Member(Username);
    //SetLabels();

}


void Me::on_pushButton_AreYouCompany_clicked()
{
    IsCompany =true;
    ui->pushButton_AreYouCompany->hide();
    CompleteCompanyInfo * n= new CompleteCompanyInfo(member->GetUsername());
    n->show();
    this->close();
}

