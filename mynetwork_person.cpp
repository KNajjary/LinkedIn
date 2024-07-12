#include "mynetwork_person.h"
#include "mydatabase.h"
#include "profileicon.h"
#include "ui_mynetwork_person.h"
#include "connectionreqicon.h"

MyNetwork_Person::MyNetwork_Person(QString u, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyNetwork_Person)
{
    ui->setupUi(this);
    person = new Person(u);
    MyDatabase db;
    RequestsCount=db.GetNumberOfRows(person->GetConnectionsTable());
    ShowRequests();
    ShowSuggests();
    //
    if(ui->stackedWidget_Req->currentIndex() != -1)
    {
        ui->label_NoInv->hide();

    }
    else
    {
        ui->pushButton_nextReq->hide();
        ui->pushButton_pevReq->hide();
    }
    //
    if(ui->stackedWidget_Sug->currentIndex() != -1){
        ui->label_NoSuggest->hide();
    }
    else
    {
        ui->pushButton_PrevSug->hide();
        ui->pushButton_nexSug->hide();
    }
}

MyNetwork_Person::~MyNetwork_Person()
{
    delete ui;
}
void MyNetwork_Person::ShowRequests()
{
    MyDatabase db;
    unsigned int i;
    for (i=1; i <= RequestsCount ; i++){
        if( db.Select(person->GetConnectionsTable(),"Status",i)!= "Pending")
            continue;
        ConnectionReqIcon * icon = new ConnectionReqIcon(person->GetUsername(),db.Select(person->GetConnectionsTable(),"Username",i));
        //icon->show();
        ui->stackedWidget_Req->addWidget(icon);
    }

}
void MyNetwork_Person::ShowSuggests()
{
    QString UsersTable="Users";
    MyDatabase db;
    unsigned int i=db.GetNumberOfRows(UsersTable);
    for(;i>0;i--){
        if(db.Select(UsersTable,"IsCompany",i).toInt()==1)
            continue;
        QString Username= db.Select(UsersTable,"Username",i);
        if(person->IsConnecting(Username) || Username==person->GetUsername())
            continue;
        ProfileIcon * icon = new ProfileIcon(person->GetUsername(),Username);
        //icon->show();
        ui->stackedWidget_Sug->addWidget(icon);
    }
}

void MyNetwork_Person::on_pushButton_nexSug_clicked()
{
    int i=ui->stackedWidget_Sug->currentIndex();
    i++;
    ui->stackedWidget_Sug->setCurrentIndex(i);
}


void MyNetwork_Person::on_pushButton_PrevSug_clicked()
{
    int i=ui->stackedWidget_Sug->currentIndex();
    i--;
    ui->stackedWidget_Sug->setCurrentIndex(i);
}


void MyNetwork_Person::on_pushButton_nextReq_clicked()
{
    int i=ui->stackedWidget_Req->currentIndex();
    i++;
    ui->stackedWidget_Req->setCurrentIndex(i);
}


void MyNetwork_Person::on_pushButton_pevReq_clicked()
{
    int i=ui->stackedWidget_Req->currentIndex();
    i--;
    ui->stackedWidget_Req->setCurrentIndex(i);
}

