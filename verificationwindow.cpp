#include "verificationwindow.h"
#include "ui_verificationwindow.h"

#include <QMessageBox>

#include "user.h"
#include "LogAndSignInWindow.h"
#include "completeuserinfowindow.h"
VerificationWindow::VerificationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VerificationWindow)
{
    ui->setupUi(this);
    VerifCode=rand()%(10000-1000)+1000;
    ui->label_EmptyCode->hide();
    ui->label_WrongCode->hide();
}

VerificationWindow::~VerificationWindow()
{
    delete ui;
}

void VerificationWindow::on_pushButton_SendCode_clicked()
{
    QMessageBox m;
    QString s;
    s.setNum(VerifCode);

    m.setText(s);
    m.exec();
    ui->pushButton_SendCode->setDisabled(true);
}


void VerificationWindow::on_pushButton_SignIn_clicked()
{
    ui->label_EmptyCode->hide();
    ui->label_WrongCode->hide();
    QString code=ui->lineEdit_Code->text();
    if(code.isEmpty()){
        ui->label_EmptyCode->show();
        return;

    }
    if(code.toUInt() != VerifCode){
        ui->label_WrongCode->show();
        ui->pushButton_SendCode->setEnabled(true);
    }
    else{

        QMessageBox::information(this,"Sign in","✨ You have signed in successfuly ✨");
        User u(LogAndSignInWindow::Username,LogAndSignInWindow::Password);
        u.SetLoggedIn(true);

        CompleteUserInfoWindow* w = new CompleteUserInfoWindow;
        w->show();
        w->SetUser(&u);
        //if(w->GetUser() == nullptr)printf("#############eeeeee");


        this->close();
        ui->~VerificationWindow();
    }



}

