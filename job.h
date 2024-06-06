#ifndef JOB_H
#define JOB_H
#include <QDateTime>
#include <QString>

class Job
{
    QString Name,
        Company,
        WorkplaceType,
        Location,
        Time,
        SkillsRequired,
        Salary,
        AppliedTable ,
        Username,//who offered
        Field,
        Profile;

    unsigned int Number;
    const QString TableName;
    bool IsClosed;
    QDateTime TimeCreated;

public:
    Job(QString,QString,QString,QString,QString,QString,QString,QString,QString);
    Job (QString ,unsigned int);
    QString GetName() const;
    QString  GetCompany()const;
    QString  GetWorkplaceType()const;
    QString  GetLocation()const;
    QString  GetTime()const;
    QString  GetSkillsRequired()const;
    QString  GetSalary()const;
    QString  GetAppliedTable()const;
    QString  GetUsername()const;//who offered
    QString  GetField()const;
    QString GetTableName()const;
    QString GetTimeCreated()const;
    QString GetProfile() const;
    QString GetStatus(QString u)const;
    bool GetIsClosed()const;
    unsigned int GetNumber()const;
};

#endif // JOB_H
