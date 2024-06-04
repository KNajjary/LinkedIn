#include "person.h"
#include "mydatabase.h"

Person::Person(QString u)
    :Member(u)
{
    MyDatabase db;
    Skills = db.SelectWhere("Users","Username",GetUsername(),"Skills",1);

}
QString Person::GetSkills()const
{
    return Skills;
}
