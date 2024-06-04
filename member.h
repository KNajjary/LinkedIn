#ifndef MEMBER_H
#define MEMBER_H
#include <QString>
#include "structs.h"
class Member
{
    QString
        Email,
        Username,
        Password,
        FirstName,
        LastName,
        Phone,
        Career,
        Picture;
    Address Address;
    unsigned int PostsCount;
    const QString TableName="Users";
    const QString PostsTable;
public:
    Member(QString);
    Member(Member const &);
    QString GetEmail()const;
    QString GetPhone()const;
    QString GetUsername()const;
    QString GetAddress()const;
    QString GetLastName()const;
    QString GetFirstName()const;
    QString GetCareer() const;
    QString GetPicture()const;
    QString GetTableName()const;
    QString GetPostsTable() const;
    unsigned int GetPostsCount() const;
    bool SetPicture(QString);
    //void Get();
};

#endif // MEMBER_H
