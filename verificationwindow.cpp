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



    QPixmap Im1("D://Linked In//VerificationWindowIm1.png");
    int Label1W,Label1H;
    Label1H=ui->ImLabel1->height();
    Label1W=ui->ImLabel1->width();
    ui->ImLabel1->setPixmap(Im1.scaled(Label1W,Label1H,Qt::KeepAspectRatio));
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
    s.prepend("Your verification code is:\n");


    m.setText(s);

    //m.text().resize(18);
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
        User  User(LogAndSignInWindow::Username,LogAndSignInWindow::Password);
        ////////////////////////////Problem:::
        User.AddToDB();
        User.SetLoggedIn(true);
        //Username = LogAndSignInWindow::Username;
        //Password = LogAndSignInWindow::Password;

        CompleteUserInfoWindow* w = new CompleteUserInfoWindow;
        //w->SetUser(&User);
        w->show();
        //
        //if(w->GetUser() == nullptr)printf("#############eeeeee");


        this->close();
        ui->~VerificationWindow();
    }



}

