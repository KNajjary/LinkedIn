#include "member.h"
#include "mydatabase.h"
Member::Member(QString u)
{
    Username=u;
    MyDatabase db;
    FirstName = db.SelectWhere(TableName,"Username",Username,"FirstName",1);
    LastName = db.SelectWhere(TableName,"Username",Username,"LastName",1);
    Email=db.SelectWhere(TableName,"Username",Username,"Email",1);
    Phone= db.SelectWhere(TableName,"Username",Username,"Phone",1);
    Career= db.SelectWhere(TableName,"Username",Username,"Career",1);
    Address.City=db.SelectWhere(TableName,"Username",Username,"AddressCity",1);
    Address.Country= db.SelectWhere(TableName,"Username",Username,"AddressCountry",1);
    Address.Province= db.SelectWhere(TableName,"Username",Username,"AddressProvince",1);
    Picture=db.SelectWhere(TableName,"Username",Username,"Picture",1);\


}
Member::Member(Member const  &m)
    :TableName(m.TableName)
{

    Email=m.Email;
    Username=m.Username;
    Password=m.Password;
    FirstName=m.FirstName;
    LastName=m.LastName;
    Phone=m.Phone;
    Career=m.Career;
    Address=m.Address;
    Picture=m.Picture;
}
QString Member::GetEmail()const
{
    return Email;
}
QString Member::GetPhone()const
{
    return Phone;
}
QString Member::GetUsername()const
{
    return Username;
}
QString Member::GetAddress()const
{
    return Address.Country+" "+Address.Province+ " "+Address.City;
}
QString Member::GetLastName()const
{
    return LastName;
}
QString Member::GetFirstName()const
{
    return FirstName;
}
QString Member::GetCareer()const
{
    return Career;
}
QString  Member::GetPicture()const
{
    return Picture;
}

