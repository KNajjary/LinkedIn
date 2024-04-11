#include "completeuserinfowindow.h"
#include "ui_completeuserinfowindow.h"

#include <QDebug>
#include <QMessageBox>
//#include <new>
#include "user.h"
//#include "verificationwindow.h"
#include "LogAndSignInWindow.h"
CompleteUserInfoWindow::CompleteUserInfoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CompleteUserInfoWindow)
{
    ui->setupUi(this);
    //user = NULL;
    ui->EmployTypeNotValid->hide();
    ui->InValidFirstNam->hide();
    ui->InvalidLastNam->hide();
    ui->MajorNotValid->hide();
    ui->InvalidEmail->hide();
    ui->InvalidPhone->hide();




}

CompleteUserInfoWindow::~CompleteUserInfoWindow()
{
    delete ui;
}
/*void CompleteUserInfoWindow::SetUser(User * u){
    User = u;
    //return;
}
*/
void CompleteUserInfoWindow::on_pushButton_Done_clicked()
{

    ui->EmployTypeNotValid->hide();
    ui->InValidFirstNam->hide();
    ui->InvalidLastNam->hide();
    ui->MajorNotValid->hide();
    ui->InvalidEmail->hide();
    ui->InvalidPhone->hide();




    qDebug() << "Enter on_pushButton_Done_clicked";
    User User(LogAndSignInWindow::Username ,LogAndSignInWindow:: Password);
    qDebug()<< LogAndSignInWindow::Username << LogAndSignInWindow::Password;
    if(! ui->lineEdit_FirstName->text().isEmpty()){

        if(User::NameCheckValid(ui->lineEdit_FirstName->text()))
            User.SetFirstName(ui->lineEdit_FirstName->text());
        else ui->InValidFirstNam->show();
    }
            //QMessageBox::critical(this," Error inserting data in database","Inserting  your first name in database is unsseccesful 😔");
            //qDebug()<< " Error inserting data in database";
    if(! ui->lineEdit_LastName->text().isEmpty()){
        if(User::NameCheckValid(ui->lineEdit_LastName->text()))
            User.SetLastName(ui->lineEdit_LastName->text());
        else ui->InvalidLastNam->show();

    }

    if(! ui->lineEdit_Email->text().isEmpty()){

        if(User::EmailCheckValid(ui->lineEdit_Email->text()))
        User.SetEmail(ui->lineEdit_Email->text());
        else ui->InvalidEmail->show();
    }
    if(! ui->lineEdit_PhoneNumber->text().isEmpty()){
        if(User::PhoneCheckValid(ui->lineEdit_PhoneNumber->text()))
            User.SetPhone(ui->lineEdit_PhoneNumber->text());
        else ui->InvalidPhone->show();
    }







    this->close();
    ui->~CompleteUserInfoWindow();
}
/*
 * const User*  CompleteUserInfoWindow::GetUser(){
    return this->User;
}
*/




/*void CompleteUserInfoWindow::on_pushButton_AdEdu_clicked()
{

}


void CompleteUserInfoWindow::on_pushButton_AddPo_clicked()
{

}*/

