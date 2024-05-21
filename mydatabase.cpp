#include "mydatabase.h"
#include <QSqlError>
MyDatabase::MyDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    /*database.setHostName();
    database.setUserName();
    database.setPassword();*/
    database.setDatabaseName("D:\\Linked In\\LinkedIn\\LinkedIn.db");
    database.open();

}
MyDatabase::~MyDatabase()
{
    database.close();
}
bool MyDatabase::Update(QString t, QString Username, QString f, QString  v)
{
    bool result=false;

    QSqlQuery qr;
    if (qr.prepare("UPDATE "+t+" SET "+ f +  " = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(v);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
        else qDebug()<< "Query execution failed: " << qr.lastError().text();
    }
    else qDebug()<< "Query execution failed: " << qr.lastError().text();

    return result;
}
bool MyDatabase::Update(QString t,QString Username,QString f,int  v){
    bool result=false;

    QSqlQuery qr;
    if (qr.prepare("UPDATE "+t+" SET "+ f +  " = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(v);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
        else qDebug()<< "Query execution failed: " << qr.lastError().text();
    }
    else qDebug()<< "Query execution failed: " << qr.lastError().text();
    return result;
}
bool MyDatabase::Update(QString t,QString Username,QString f, bool v){
    bool result=false;
    unsigned int n;
    if(v)n=1;
    else n=0;

    QSqlQuery qr;
    if (qr.prepare("UPDATE "+t+" SET "+ f + " = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
        else qDebug()<< "Query execution failed: " << qr.lastError().text();
    }
    else qDebug()<< "Query execution failed: " << qr.lastError().text();

    return result;
}
void MyDatabase::CreatePostsTable(QString name){
    QSqlQuery qr;
    if(
       qr.prepare( "CREATE TABLE IF NOT EXISTS " +name+
                   " ( TimeSent TEXT NOT NULL, Picture	TEXT,Text TEXT, Username TEXT NOT NULL , CommentText TEXT, CommentPicture TEXT, CommentTimeSent	TEXT,CommentUsername TEXT , LikeTime TEXT, LikeUsername	TEXT, RepostCounter INTEGER, ShareCounter	INTEGER , CommentCounter INTEGER );")
        )
    {
        if(!qr.exec()) qDebug()<< qr.lastError().text();
    }
    else qDebug()<< qr.lastError().text();
}
//bool MyDatabase::CreateMessagesTable(){

//}
