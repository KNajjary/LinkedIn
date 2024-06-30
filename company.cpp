#include "company.h"
#include "mydatabase.h"

Company::Company(QString u)
    :Member(u)
{
    MyDatabase db;
    CompanyName = db.SelectWhere("Users","Username",GetUsername(),"CompanyName",1);
    StartYear = db.SelectWhere("Users","Username",GetUsername(),"CompanyStartYear",1);
    FollowersTable=GetUsername()+"_Followers";

}
QString Company::GetCompanyName() const
{
    return CompanyName;
}
QString Company::GetStartYear() const
{
    return StartYear;
}
QString Company::GetFollowersTable() const
{
    return FollowersTable;
}
QString Company::GetFollower(unsigned int n) const
{
     MyDatabase db;
    return db.Select(FollowersTable,"Username",n);
}
void Company::AddFollower(QString u)
{
    MyDatabase db;
    db.InsertFollower_Following_Connecting(FollowersTable,u);
}
