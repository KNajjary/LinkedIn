#ifndef MYDATABASE_H
#define MYDATABASE_H
//-----------------------------------------------------------
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
//----------------------------------------------------------------
class MyDatabase
{
    QSqlDatabase database;
public:
    MyDatabase();
    ~MyDatabase();
    //
    bool Update(QString , QString,QString ,QString ,QString  );//table/username/field/value
    bool Update(QString  , QString , QString , QString , bool  );
    bool Update(QString ,QString,int ,QString ,int  );
    //
    bool InsertComment(QString,QString,QString,QString,QString);
    bool InsertPost(QString , QString,QString,QString);
    //
    QString SelectWhere(QString , QString ,QString ,QString  ,unsigned int);//table / where=value/ find nth field
    QString SelectWhere(QString , QString ,int ,QString  ,unsigned int);//table / where=value/ find nth field
    QString SelectMax(QString , QString);
    QString Select(QString ,QString ,unsigned int );
    void CreatePostsTable(QString);
    void CreateLikeTable(QString);
    void CreateCommentTable(QString);
    //bool CreateMessagesTable();
};
//----------------------------------------------------------
#endif // MYDATABASE_H
