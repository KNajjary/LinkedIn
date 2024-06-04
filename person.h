#ifndef PERSON_H
#define PERSON_H

#include "member.h"
#include <QString>
class Person : public Member
{
    QString Skills;
public:
    Person(QString);
    QString GetSkills()const;
};

#endif // PERSON_H
