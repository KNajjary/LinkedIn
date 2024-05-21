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
    bool Update(QString ,QString ,QString ,QString  );//table/username/field/value
    bool Update(QString ,QString ,QString ,bool  );
    bool Update(QString ,QString ,QString ,int  );
    void CreatePostsTable(QString);
    //bool CreateMessagesTable();
};
//----------------------------------------------------------
#endif // MYDATABASE_H
