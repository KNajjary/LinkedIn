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
    if(ui->stackedWidget_Req->currentIndex() != -1)
        ui->label_NoInv->hide();
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
        icon->show();
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
        if(person->IsConnecting(Username))
            continue;
        ProfileIcon * icon = new ProfileIcon(person->GetUsername(),Username);
        icon->show();
        ui->stackedWidget_Sug->addWidget(icon);
    }
}
