#include "completeuserinfowindow.h"
#include "ui_completeuserinfowindow.h"

#include <QMessageBox>
CompleteUserInfoWindow::CompleteUserInfoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CompleteUserInfoWindow)
{
    ui->setupUi(this);
    user=nullptr;




}

CompleteUserInfoWindow::~CompleteUserInfoWindow()
{
    delete ui;
}
void CompleteUserInfoWindow::SetUser(User *u){
    user= u;
}

void CompleteUserInfoWindow::on_pushButton_Done_clicked()
{
    if(! ui->lineEdit_FirstName->text().isEmpty())
        if(! user->SetFirstName(ui->lineEdit_FirstName->text()))
            QMessageBox::critical(this," Error inserting data in database","Inserting  your first name in database is unsseccesful 😔");;

}
const User*  CompleteUserInfoWindow::GetUser(){
    return this->user;
}

