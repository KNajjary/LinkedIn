#include "LogAndSignInWindow.h"
#include "ui_LogAndSignInWindow.h"

#include "functions.h"
#include "user.h"
#include "verificationwindow.h"
//#include <QRandomGenerator>
QString LogAndSignInWindow::Password=NULL;
QString LogAndSignInWindow::Username=NULL;

LogAndSignInWindow::LogAndSignInWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LogAndSignInWindow)
{
    ui->setupUi(this);

    ui->PushButton_Continue->hide();
    ui->SignInInfo->hide();
    ui->label_PassReq->hide();
    ui->label_UsernReq->hide();
    ui->label_CapchaCode->hide();
    ui->lineEdit_Capcha->hide();
    ui->label_CapchaReq->hide();
    ui->label_WrongCapcha->hide();
    ui->label_WrongPassword->hide();
    ui->label_UsernameNotFound->hide();
    ui->label_UsernamAlreadyExists->hide();




    CapchaCode=rand()%(100000-1000)+1000;
    ui->label_CapchaCode->setText(QString::number(CapchaCode));
}

LogAndSignInWindow::~LogAndSignInWindow()
{
    delete ui;
}

void LogAndSignInWindow::on_PushButton_LogIn_clicked()
{
    ui->label_WrongPassword->hide();
    ui->label_UsernameNotFound->hide();
    ui->label_PassReq->hide();
    ui->label_UsernReq->hide();

    QString un=ui->LineEdit_Username->text(),
        p=ui->LineEdit_Password->text();
    if(p.isEmpty() || un.isEmpty()){
        if(un.isEmpty())ui->label_UsernReq->show();
        if(p.isEmpty())ui->label_PassReq->show();
        return;
    }


    if(User::CheckPassword(un,p)==1){
        this->close();
        ui->~LogAndSignInWindow();
        return;
    }
    if(User::CheckPassword(un,p)==0){
        ui->label_WrongPassword->show();
        return;
    }

    if(User::CheckPassword(un,p)==2){
        ui->label_UsernameNotFound->show();
        return;
    }







}





void LogAndSignInWindow::on_pushButton_HaventSigned_clicked()
{
    ui->SignInInfo->show();
    ui->PushButton_LogIn->hide();
    ui->pushButton_HaventSigned->hide();
    ui->PushButton_Continue->show();
    ui->label_CapchaCode->show();
    ui->lineEdit_Capcha->show();
    ui->label_WrongPassword->hide();
    ui->label_UsernameNotFound->hide();
    ui->label_PassReq->hide();
    ui->label_UsernReq->hide();
    ui->label_UsernamAlreadyExists->hide();
}


void LogAndSignInWindow::on_PushButton_Continue_clicked()
{
    ui->label_PassReq->hide();
    ui->label_UsernReq->hide();
    ui->label_CapchaReq->hide();
    ui->label_WrongCapcha->hide();
    ui->label_UsernamAlreadyExists->hide();

    QString un=ui->LineEdit_Username->text(),
        p=ui->LineEdit_Password->text(),
        capcha= ui->lineEdit_Capcha->text();
    if(!un.isEmpty() && !p.isEmpty() && !capcha.isEmpty()){

        if(User::DoesUsernameExist(un))ui->label_UsernamAlreadyExists->show();

        else if(capcha.toUInt() == CapchaCode)
        {
            Username=un;
            Password=p;

            //


            this->close();
            ui->~LogAndSignInWindow();
            VerificationWindow *vw=new VerificationWindow;
            vw->show();
        }
        else{
            ui->label_WrongCapcha->show();
        }
    }
    else{
        if(p.isEmpty())ui->label_PassReq->show();

        if(un.isEmpty())ui->label_UsernReq->show();
        if(capcha.isEmpty())ui->label_CapchaReq->show();
    }



}
