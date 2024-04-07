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

    qDebug() << "Enter on_pushButton_Done_clicked";
    User User(LogAndSignInWindow::Username ,LogAndSignInWindow:: Password);
    qDebug()<< LogAndSignInWindow::Username << LogAndSignInWindow::Password;
    if(! ui->lineEdit_FirstName->text().isEmpty())
        if(! User.SetFirstName(ui->lineEdit_FirstName->text()))
            //QMessageBox::critical(this," Error inserting data in database","Inserting  your first name in database is unsseccesful 😔");
            qDebug()<< " Error inserting data in database";
    if(! ui->lineEdit_LastName->text().isEmpty())
        User.SetLastName(ui->lineEdit_LastName->text());
    if(! ui->lineEdit_Email->text().isEmpty())
        User.SetEmail(ui->lineEdit_Email->text());
    if(! ui->lineEdit_PhoneNumber->text().isEmpty())
        User.SetPhone(ui->lineEdit_PhoneNumber->text());
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

