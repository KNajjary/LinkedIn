#ifndef COMPANY_H
#define COMPANY_H

#include "member.h"
#include <QString>
class Company : public Member
{
    QString CompanyName,
        StartYear;

public:
    Company(QString);
    QString GetCompanyName() const;
    QString GetStartYear() const;
};

#endif // COMPANY_H
