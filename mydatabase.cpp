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
bool MyDatabase::Update(QString t, QString c, QString Username, QString f, QString  v)
{
    bool result=false;

    QSqlQuery qr;
    if (qr.prepare("UPDATE "+t+" SET "+ f +  " = ? WHERE "+c+" = ? ;"))
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
bool MyDatabase::Update(QString t,QString column,int value,QString f,int  v)
{
    bool result=false;

    QSqlQuery qr;
    if (qr.prepare("UPDATE "+t+" SET "+ f +  " = ? WHERE "+column+" = ? ;"))
    {
        qr.addBindValue(v);
        qr.addBindValue(value);
        if(qr.exec())
            result=true;
        else qDebug()<< "Query execution failed: " << qr.lastError().text();
    }
    else qDebug()<< "Query execution failed: " << qr.lastError().text();
    return result;
}
bool MyDatabase::Update(QString t,QString c,QString Username,QString f, bool v)
{
    bool result=false;
    unsigned int n;
    if(v)n=1;
    else n=0;

    QSqlQuery qr;
    if (qr.prepare("UPDATE "+t+" SET "+ f + " = ? WHERE "+c+" = ? ;"))
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
    QSqlQuery qr; //Username TEXT NOT NULL
    if(
       qr.prepare( "CREATE TABLE IF NOT EXISTS " +name+
                   " ( TimeSent TEXT NOT NULL, Picture	TEXT,Text TEXT, RepostCounter INTEGER, ShareCounter	INTEGER , CommentCounter INTEGER , LikeCounter INTEGER  , RowNumber INTEGER , PRIMARY KEY( RowNumber AUTOINCREMENT) );")
        )
    {
        if(!qr.exec()) qDebug()<< qr.lastError().text();
    }
    else qDebug()<< qr.lastError().text();
}
void MyDatabase::CreateCommentTable(QString name)
{
    QSqlQuery qr;
    if(
        qr.prepare( "CREATE TABLE IF NOT EXISTS " +name+
                   " (Text TEXT , Picture TEXT, TimeSent TEXT, Username TEXT , RowNumber INTEGER , PRIMARY KEY( RowNumber AUTOINCREMENT) );")
        )
    {
        if(!qr.exec()) qDebug()<< qr.lastError().text();
    }
    else qDebug()<< qr.lastError().text();
}
void MyDatabase::CreateLikeTable(QString name)
{
    QSqlQuery qr;
    if(
        qr.prepare(
            "CREATE TABLE IF NOT EXISTS " +name+
            " ( Time TEXT,"
            " Username	TEXT , RowNumber INTEGER , PRIMARY KEY( RowNumber AUTOINCREMENT) );"
            )
        )
    {
        if(!qr.exec()) qDebug()<< qr.lastError().text();
    }
    else qDebug()<< qr.lastError().text();
}
//bool MyDatabase::CreateMessagesTable(){

//}
QString MyDatabase::SelectWhere(QString t, QString where,QString value,QString field ,unsigned int nth)//starting from 1
{
    QSqlQuery qr;
    qr.exec("SELECT "+field+" FROM "+t+" WHERE "+where+" ='"+value+"' ;");
    qr.seek(nth-1);
    return qr.value(0).toString();
}
QString MyDatabase::SelectWhere(QString t, QString where,int value,QString field ,unsigned int nth)//starting from 1
{
    QSqlQuery qr;
    qr.prepare("SELECT "+field+" FROM "+t+" WHERE "+where+" = ? ;");
    qr.addBindValue(value);
    qr.exec();
    qDebug()<< qr.lastError().text();
    qr.seek(nth-1);
    return qr.value(0).toString();
}
QString MyDatabase::Select(QString t,QString field ,unsigned int nth)//starting from 1
{
    QSqlQuery qr;
    qr.exec("SELECT "+field+" FROM "+t+" ;");
    qr.seek(nth-1);
    return qr.value(0).toString();
}
bool MyDatabase::InsertComment(QString TableName,QString Username,QString Text,QString Picture,QString Time)
{
    MyDatabase db;
    QSqlQuery qr;
    qr.prepare("INSERT INTO "+TableName+" ("
                                            "CommentUsername , "
                                            "CommentText , "
                                            "CommentPicture , "
                                            "CommentTimeSent )"
                                            "VALUES (?,?,?,?);");
    qr.addBindValue(Username);
    qr.addBindValue(Text);
    qr.addBindValue(Picture);
    qr.addBindValue(Time);

    if(!qr.exec()){
        qDebug() << "error adding comment to table in database" << qr.lastError().text() ;
        return false;
    }
    int ComNum = SelectWhere(TableName,"RowNumber",1,"CommentCounter",1).toInt();
    Update(TableName,"RowNumber",1,"CommentCounter",++ComNum);
    return true;
}
bool MyDatabase::InsertPost(QString TableName, QString Text,QString Picture,QString TimeSent)
{
    MyDatabase db;
    QSqlQuery qr;
    if(! qr.prepare("INSERT INTO "+TableName+" ("
                                            "TimeSent , "
                                            "Picture , "
                                            "Text , "
                                            "RepostCounter ,"
                                            "ShareCounter ,"
                                            "CommentCounter ,"
                                            "LikeCounter "
                                            " ) VALUES (?,?,?,?,?,?,?);") )
    {
        qDebug() << "error 1 adding post to table in database" << qr.lastError().text() ;
        return false;
    }
    qr.addBindValue(TimeSent);
    qr.addBindValue(Picture);
    qr.addBindValue(Text);
    qr.addBindValue(0);
    qr.addBindValue(0);
    qr.addBindValue(0);
    qr.addBindValue(0);


    if(!qr.exec()){
        qDebug() << "error 2 adding post to table in database" << qr.lastError().text() ;
        return false;
    }

    return true;

}
QString MyDatabase::SelectMax(QString table, QString max)
{
    QSqlQuery qr;
    if( ! qr.prepare("SELECT MAX("+max +") FROM "+table+" ;"))
    {
        qDebug()<<"error1 "<<qr.lastError().text();
        return "";
    }
    //qr.addBindValue(max);
    if(! qr.exec())
    {
        qDebug()<<"error2 "<<qr.lastError().text();
        return "";
    }
    qr.next();

    return qr.value(0).toString();
}
