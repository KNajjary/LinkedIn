#ifndef PERSON_H
#define PERSON_H

#include "member.h"
#include <QString>
class Person : public Member
{
    QString Skills,
        FollowingsTable,//companys I am following
        ConnectingsTable,//people I am connected to
        ConnectionsTable;//peaple who want follow me
public:
    Person(QString);
    QString GetSkills()const;
    QString GetConnectingsTable() const;
    QString GetConnectionsTable() const;
    void FollowCompany(QString);
    void RequestConnection(QString);
    void SetStateConnection(QString,QString);
    bool IsConnecting(QString);//is connecting to a person or not
    bool IsFollowing(QString);//is following a company  or not
};

#endif // PERSON_H
