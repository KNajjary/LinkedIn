#ifndef STRUCTS_H
#define STRUCTS_H

#include <QApplication>

struct Date{
    unsigned short int Month,
        Year,
        Day;
};
struct Education{
    QString Major,
        SchoolName,
        Grade;
    bool Finished;
    unsigned int  StartYear,
        EndYear;
};
struct job{
    QString
        CompanyName,
        Post,
        EmploymentTipe;
    unsigned int  StartYear,
        EndYear;
};
struct Address{
    QString Country,
        Province,
        City;
};
/*struct PassState{
    unsigned int state;
    //0 means password is incorrect
    //1 means password is correct
    //2 means username does not exist
};*/

#endif // STRUCTS_H
