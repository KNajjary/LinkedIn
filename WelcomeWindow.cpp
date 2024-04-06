#include "WelcomeWindow.h"
#include "LogAndSignInWindow.h"

#include "ui_WelcomeWindow.h"
#include <QPixmap>
WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QPixmap Im1("D://Linked In//WelcomeWindowIm1.jpg");
    int Label1W,Label1H;
    Label1H=ui->ImLabel1->height();
    Label1W=ui->ImLabel1->width();
    ui->ImLabel1->setPixmap(Im1.scaled(Label1W,Label1H,Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}
/*void WelcomeWindow::IsPushButton1Pressed(){
    if(ui->PushButton1->isDown()){
        ui->~WelcomeWindow();
        JoinAndSingInWindow w;


    }
}*/

void WelcomeWindow::on_PushButton1_clicked()
{
    this->close();
    ui->~WelcomeWindow();

    //return true;

    LogAndSignInWindow *lw = new LogAndSignInWindow;
    //jw.activateWindow();
    lw->show();

    //return &w;
}

