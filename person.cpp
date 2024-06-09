#include "person.h"
#include "mydatabase.h"

Person::Person(QString u)
    :Member(u)
{
    FollowingsTable=GetUsername()+"_Followings";
    ConnectingsTable=GetUsername()+"_Connectings";
    ConnectionsTable=GetUsername()+"_Connections";
    MyDatabase db;
    Skills = db.SelectWhere("Users","Username",GetUsername(),"Skills",1);

}
QString Person::GetSkills()const
{
    return Skills;
}
void Person::FollowCompany(QString u)
{
    MyDatabase db;
    db.CreateFollowers_Following_Table(u+"_Followers");
    db.CreateFollowers_Following_Table(FollowingsTable);
    db.InsertFollower_Following_Connecting(u+"_Followers",GetUsername());
    db.InsertFollower_Following_Connecting(FollowingsTable,u);
}
void Person::RequestConnection(QString u)
{
    MyDatabase db;
    db.CreateConnectingTable(ConnectingsTable);
    db.CreateConnectionsTable(u+"_Connections");
    db.InsertConnection(u+"_Connections",GetUsername(),"Pending");
}
void Person::SetStateConnection(QString u,QString state)
{
    MyDatabase db;
    db.Update(ConnectionsTable,"Username",u,"Status",state);
}

