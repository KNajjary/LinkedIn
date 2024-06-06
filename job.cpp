#include "job.h"
#include "mydatabase.h"

Job::Job(QString u ,QString name,QString comp,QString workplace,QString location,QString time,QString skills,QString salary,QString field)
    : TableName(u+"_Jobs")

{
    Username=u;
    Name=name;
    Company=comp;
    WorkplaceType=workplace;
    Location=location;
    Time=time;
    SkillsRequired=skills;
    Salary=salary;
    IsClosed=false;
    TimeCreated=QDateTime::currentDateTime() ;
    Field=field;
    MyDatabase db;
    db.CreateJobsTable(TableName);
    db.InsertJob(TableName,  Name, Company, WorkplaceType, Location, Time, SkillsRequired, Salary,TimeCreated.toString(),Field);
    Number=db.SelectWhere(TableName,"TimeCreated",TimeCreated.toString(),"Number",1).toInt();
    qDebug()<< Number;
    AppliedTable = Username +"_Job_"+QString::number(Number)+"_Applys";
    db.CreateJobApplyTable(AppliedTable);



}
Job::Job (QString username,unsigned int number)
    : TableName(username+"_Jobs")
{
    Username=username;
    Number=number;
    MyDatabase db;
    Name=db.SelectWhere(TableName,"Number",Number,"Name",1);
    Company=db.SelectWhere(TableName,"Number",Number,"Company",1);
    WorkplaceType=db.SelectWhere(TableName,"Number",Number,"WorkplaceType",1);
    Location=db.SelectWhere(TableName,"Number",Number,"Location",1);
    Time=db.SelectWhere(TableName,"Number",Number,"Time",1);
    SkillsRequired=db.SelectWhere(TableName,"Number",Number,"SkillsRequired",1);
    Salary=db.SelectWhere(TableName,"Number",Number,"Salary",1);
    if(db.SelectWhere(TableName,"Number",Number,"IsClosed",1).toInt()==0)
        IsClosed=false;
    else IsClosed=true;
    TimeCreated = QDateTime::fromString(db.SelectWhere(TableName,"Number",Number,"TimeCreated",1));
    Field=db.SelectWhere(TableName,"Number",Number,"Field",1);
    Profile=db.SelectWhere("Users","Username",Username,"Picture",1);
    AppliedTable = Username +"_Job_"+QString::number(Number)+"_Applys";
}
QString Job::GetName() const
{
    return Name;
}
QString  Job::GetCompany()const
{
    return Company;
}
QString  Job::GetWorkplaceType()const
{
    return WorkplaceType;
}
QString  Job::GetLocation()const
{
    return Location;
}
QString  Job::GetTime()const
{
    return Time;

}
QString  Job::GetSkillsRequired()const
{
    return SkillsRequired;
}
QString  Job::GetSalary()const
{
    return Salary;
}
QString  Job::GetAppliedTable()const
{
    return AppliedTable;
}
QString  Job::GetUsername()const
{
    return Username;
}
QString  Job::GetField()const
{
    return Field;
}
QString Job::GetTableName()const
{
    return TableName;
}
QString Job::GetTimeCreated()const
{
    return TimeCreated.toString();
}
bool Job::GetIsClosed()const
{
    return IsClosed;
}
unsigned int Job::GetNumber()const
{
    return Number;
}
QString  Job::GetProfile() const
{
    return Profile;
}
QString Job::GetStatus(QString u)const
{
    MyDatabase db;
    return db.SelectWhere(AppliedTable,"Username",u,"Status",1);
}
