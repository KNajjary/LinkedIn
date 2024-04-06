#include "user.h"
#include "functions.h"
//#include <QDebug>

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include <QSqlError>
/*
 QSqlDatabase database;
database = QSqlDatabase::addDatabase("QSQLITE");
database.setDatabaseName("d:\\Linked In\\LinkedIn.db");
database.open():
*/
User::User(QString na,QString pa)
{
    Username=na;
    Password=pa;

    QSqlDatabase database;
    SetupDatabase(database);

    QSqlQuery qr;
    qr.prepare("INSERT INTO Users ("
               "Username,"
               "Password)"
               "VALUES (?,?);");
    qr.addBindValue(na);
    qr.addBindValue(pa);

    if(!qr.exec()){
        qDebug() << "error adding values to User table in database" ;
    }


    CloseDatabase(database);



}
void User::SetLoggedIn(bool state){
    LoggedIn=state;


}
bool User::DoesUsernameExist(QString un){
    QSqlDatabase database;
    SetupDatabase(database);
    bool found=false;
    QSqlQuery qr;
    qr.exec();
    qr.exec("SELECT * FROM Users WHERE Username='"+un+"'");
    if(qr.first())found=true;


    CloseDatabase(database);
    if(found)return true;
    else return false;
}
unsigned int User::CheckPassword(QString un, QString p){
    //0 means password is incorrect
    //1 means password is correct
    //2 means username does not exist

    unsigned int state=3;
    if (!DoesUsernameExist(un))  state=2;
    else {
        QSqlDatabase database;
        SetupDatabase(database);
        QSqlQuery qr;

        qr.exec("SELECT Password FROM Users WHERE Username='"+un+"'");
        qr.first();
        if(qr.value(0).toString() == p){
            state=1;
        }
        else{
            state=0;
        }
        CloseDatabase(database);
    }

    return state;
}


bool User::SetFirstName(QString n){
    FirstName=n;


    bool result=true;

    QSqlDatabase database;
    SetupDatabase(database);

    QSqlQuery qr;
    qr.prepare("UPDATE Users SET FirstName = ? WHERE Username = ? ;");
    qr.addBindValue(n);
    qr.addBindValue(Username);


    if(! qr.exec()){
        result=false;
        //QSqlError er = ;

        qDebug() << qr.lastError();

    }

    //qr.first();

    CloseDatabase(database);
    return result;




}
/*
bool User::SetLastName(QString n){
    LastName=n;

    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    qr.exec("SELECT LastName FROM Users WHERE Username='"+Username+"'");
    if(qr.first())
        qr.value(0).setValue(n);


    CloseDatabase(database);
}

bool User::SetPhone(QString){
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;


    CloseDatabase(database);
}
bool User::SetEmail(QString){
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;


    CloseDatabase(database);
}
bool User::SetOver18(bool){
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;


    CloseDatabase(database);
}
bool User::SetAddress(struct Address){
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;


    CloseDatabase(database);
}
bool User::SetIsStudent(bool){
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;


    CloseDatabase(database);
}
bool User::SetBirthDate(struct Date){
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;


    CloseDatabase(database);
}
*/