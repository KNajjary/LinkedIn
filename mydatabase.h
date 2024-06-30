#ifndef MYDATABASE_H
#define MYDATABASE_H
//-----------------------------------------------------------
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "job.h"

//----------------------------------------------------------------
class MyDatabase
{
    QSqlDatabase database;
public:
    MyDatabase();
    ~MyDatabase();
    //
    bool Update(QString , QString,QString ,QString , QString  );//table/username/field/value
    bool Update(QString  , QString , QString , QString , bool  );
    bool Update(QString ,QString,int ,QString ,int  );
    //
    bool InsertComment(QString,QString,QString,QString,QString);
    bool InsertPost(QString , QString,QString,QString,bool);
    bool InsertJob(QString TableName,QString  Name,QString Company,QString WorkplaceType,QString Location,QString Time,QString SkillsRequired,QString Salary,QString TimeCreated,QString f);
    bool InsertJob(Job);
    bool InsertApply(QString,QString,QString);
    bool InsertInJobs(QString,unsigned int);
    bool InsertFollower_Following_Connecting(QString,QString);
    bool InsertConnection(QString,QString,QString);
    bool InsertLike(QString,QString,QString);

    //
    QString SelectWhere(QString , QString ,QString ,QString  ,unsigned int);//table / where=value/ find nth field
    QString SelectWhere(QString , QString ,int ,QString  ,unsigned int);//table / where=value/ find nth field
    QString SelectMax(QString , QString);
    QString Select(QString ,QString ,unsigned int );
    //
    void CreatePostsTable(QString);
    void CreateLikeTable(QString);
    void CreateCommentTable(QString);
    void CreateJobsTable(QString);
    void CreateJobApplyTable(QString);
    void CreateConnectionsTable(QString);
    void CreateConnectingsTable(QString);
    void CreateFollowers_Following_Table(QString);
    //
    unsigned int GetNumberOfRows(QString);
    //unsigned int GetNumberOfRowsWith(QString,QString,QString);
    bool DoesExist(QString ,QString ,QString );
    //bool CreateMessagesTable();
};
//----------------------------------------------------------
#endif // MYDATABASE_H
