#ifndef COMPANY_H
#define COMPANY_H

#include "member.h"
#include <QString>
class Company : public Member
{
    QString CompanyName,
        StartYear,
        FollowersTable;

public:
    Company(QString);
    QString GetCompanyName() const;
    QString GetStartYear() const;
    QString GetFollowersTable() const;
    QString GetFollower(unsigned int) const;
};

#endif // COMPANY_H
