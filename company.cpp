#include "company.h"
#include "mydatabase.h"

Company::Company(QString u)
    :Member(u)
{
    MyDatabase db;
    CompanyName = db.SelectWhere("Users","Username",GetUsername(),"CompanyName",1);
    StartYear = db.SelectWhere("Users","Username",GetUsername(),"CompanyStartYear",1);

}
QString Company::GetCompanyName() const
{
    return CompanyName;
}
QString Company::GetStartYear() const
{
    return StartYear;
}
