#include "completecompanyinfo.h"
#include "mydatabase.h"
#include "ui_completecompanyinfo.h"
#include "functions.h"
CompleteCompanyInfo::CompleteCompanyInfo(QString u ,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CompleteCompanyInfo)
{
    ui->setupUi(this);
    Username=u;
    ui->InValidFirstNam->hide();
    ui->InvalidLastNam->hide();
    ui->InvalidEmail->hide();
    ui->InvalidPhone->hide();

}

CompleteCompanyInfo::~CompleteCompanyInfo()
{
    delete ui;
}

void CompleteCompanyInfo::on_pushButton_Done_clicked()
{
    ui->InValidFirstNam->hide();
    ui->InvalidLastNam->hide();
    ui->InvalidEmail->hide();
    ui->InvalidPhone->hide();

    if(! ui->lineEdit_FirstName->text().isEmpty())
    {
        if(! IsMadeOfLetters(ui->lineEdit_FirstName->text()))
        {
            ui->InValidFirstNam->show();
            return;
        }

    }
    if(! ui->lineEdit_LastName->text().isEmpty())
    {
        if(! IsMadeOfLetters(ui->lineEdit_LastName->text()))
        {
            ui->InvalidLastNam->show();
            return;
        }

    }
    if(! ui->lineEdit_Email->text().isEmpty())
    {
        if(! IsEmailValid(ui->lineEdit_Email->text()))
        {
            ui->InvalidEmail->show();
            return;
        }
    }
    if(! ui->lineEdit_PhoneNumber->text().isEmpty())
    {
        if(! IsMadeOfNumbers(ui->lineEdit_PhoneNumber->text()))
        {
            ui->InvalidPhone->show();
            return;
        }
    }
    MyDatabase db;
    db.Update("Users", Username ,"FirstName", ui->lineEdit_FirstName->text());
    db.Update("Users", Username ,"LastName", ui->lineEdit_LastName->text());
    db.Update("Users", Username ,"Email", ui->lineEdit_Email->text());
    db.Update("Users", Username ,"Phone", ui->lineEdit_PhoneNumber->text());
    db.Update("Users", Username ,"AddressCity", ui->comboBox_City->currentText());
    db.Update("Users", Username ,"AddressProvince", ui->comboBox_Province->currentText());
    db.Update("Users", Username ,"AddressCountry", ui->comboBox_Country->currentText());
    db.Update("Users", Username ,"Career", ui->comboBox_career->currentText());
    db.Update("Users", Username ,"CompanyStartYear", ui->spinBox_PrevEmploymentsStartYear->text());
    db.Update("Users", Username ,"CompanyName", ui->lineEdit_PrevEmploymentsCompanyName->text());
    db.Update("Users", Username ,"IsCompany", true );



}

