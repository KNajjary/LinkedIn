#include "connectionreqicon.h"
#include "ui_connectionreqicon.h"

ConnectionReqIcon::ConnectionReqIcon(QString ac , QString req, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ConnectionReqIcon)
{
    ui->setupUi(this);
    RequestedPerson= new Person(req);
    AcceptedPerson = new Person(ac);
    //
    ui->label_Name->setText(RequestedPerson->GetFirstName()+" "+RequestedPerson->GetLastName());
    QPixmap Im(RequestedPerson->GetPicture());
    unsigned int h = ui->label_Prof->height();
    unsigned int w=ui->label_Prof->width();
    ui->label_Prof->setPixmap(Im.scaled(w,h,Qt::KeepAspectRatioByExpanding));
    //

}

ConnectionReqIcon::~ConnectionReqIcon()
{
    delete ui;
}

void ConnectionReqIcon::on_pushButton_Accept_clicked()
{
    AcceptedPerson->SetStateConnection(RequestedPerson->GetUsername(),"Accepted");
}


void ConnectionReqIcon::on_pushButton_Ignore_clicked()
{
    AcceptedPerson->SetStateConnection(RequestedPerson->GetUsername(),"Ignored");
}

