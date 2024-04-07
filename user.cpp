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

}
void User::AddToDB(){
    if(Username.isEmpty() || Password.isEmpty()){
        qDebug()<< "Wrong place to call AddToDB function";
        return;
    }
    QSqlDatabase database;
    SetupDatabase(database);

    QSqlQuery qr;
    qr.prepare("INSERT INTO Users ("
               "Username,"
               "Password)"
               "VALUES (?,?);");
    qr.addBindValue(Username);
    qr.addBindValue(Password);

    if(!qr.exec()){
        qDebug() << "error adding values to User table in database" ;
    }


    CloseDatabase(database);
    return;
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
unsigned int User::CheckPasswordInDB(QString un, QString p){
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

    qDebug()<< "Start:::";

    bool result=true;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    /*qr.exec("SELECT FirstName FROM Users WHERE Username='"+Username+"'");

    qr.first();
    qr.value(0).setValue(&n);*/
    //"INSERT INTO Users ( FirstName ) VALUES (?) WHERE Username = ? ;"

    if (! qr.prepare("UPDATE Users SET FirstName = ? WHERE Username = ? ;"))
    {
        qDebug() << "Query preparation failed:" << qr.lastError().text();

    }
    else{
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(! qr.exec()){
            result=false;
            //QSqlError er = ;

            qDebug() << "##Error"<< "Query execution failed:" << qr.lastError().text();

        }
    }



    /*qr.prepare("UPDATE Users SET FirstName = :n WHERE Username = :u ;");
    //qr.isValid();
    qr.bindValue(":n", n);

    qr.bindValue(":u",Username);

    qr.prepare("UPDATE Users SET FirstName = '"+n+"' WHERE Username = '"+Username+"' ;");
    //qr.isValid();
    qr.addBindValue(n);

    qr.addBindValue(Username);*/


    CloseDatabase(database);
    return result;
}

bool User::SetLastName(QString n){
    LastName=n;

    //qDebug()<< "Start:::";

    bool result=true;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (! qr.prepare("UPDATE Users SET LastName = ? WHERE Username = ? ;"))
    {
        qDebug() << "in function User::SetLastName : Query preparation failed :" << qr.lastError().text();

    }
    else{
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(! qr.exec()){
            result=false;
            //QSqlError er = ;

            qDebug() <<  "in function User::SetLastName : Query execution failed:" << qr.lastError().text();

        }
    }
    CloseDatabase(database);
    return result;
}

bool User::SetPhone(QString s){
    Phone=s;

    bool result=true;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (! qr.prepare("UPDATE Users SET Phone = ? WHERE Username = ? ;"))
    {
        qDebug() << "in function User::SetPhone : Query preparation failed :" << qr.lastError().text();

    }
    else{
        qr.addBindValue(s);
        qr.addBindValue(Username);
        if(! qr.exec()){
            result=false;
            //QSqlError er = ;

            qDebug() <<  "in function User::SetPhone : Query execution failed:" << qr.lastError().text();

        }
    }
    CloseDatabase(database);
    return result;
}
bool User::SetEmail(QString n){
    Email=n;

    bool result=true;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (! qr.prepare("UPDATE Users SET Email = ? WHERE Username = ? ;"))
    {
        qDebug() << "in function User::SetEmail : Query preparation failed :" << qr.lastError().text();

    }
    else{
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(! qr.exec()){
            result=false;
            //QSqlError er = ;

            qDebug() <<  "in function User::SetEmail : Query execution failed:" << qr.lastError().text();

        }
    }
    CloseDatabase(database);
    return result;
}
/*bool User::SetOver18(bool){
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;


    CloseDatabase(database);
}
bool User::SetAddress(struct Address){
    Phone=s;

    bool result=true;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (! qr.prepare("UPDATE Users SET Phone = ? WHERE Username = ? ;"))
    {
        qDebug() << "in function User::SetPhone : Query preparation failed :" << qr.lastError().text();

    }
    else{
        qr.addBindValue(s);
        qr.addBindValue(Username);
        if(! qr.exec()){
            result=false;
            //QSqlError er = ;

            qDebug() <<  "in function User::SetPhone : Query execution failed:" << qr.lastError().text();

        }
    }
    CloseDatabase(database);
    return result;
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
