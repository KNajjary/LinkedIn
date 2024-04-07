#ifndef USER_H
#define USER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "structs.h"

class User
{
    QString
        Email,
        Username,
        Password,
        FirstName,
        LastName,
        Phone;
    Address Address;
    bool Over18,
        IsStudent,
        LoggedIn;
        //Verified

    unsigned int NumOfPrevEmploymets;
    unsigned int NumOfDegrees;
    Date BirthDate;
    Education EducationInfo[10];
    Job PrevEmploymets[10];

public:
    User(QString , QString);
    void AddToDB();

    bool SetFirstName(QString);
    bool SetLastName(QString);
    bool SetPhone(QString);
    bool SetEmail(QString);


    /*bool SetOver18(bool);
    bool SetAddress(struct Address);
    bool SetIsStudent(bool);
    bool SetBirthDate(struct Date);
*/
    void SetLoggedIn(bool);
    static bool DoesUsernameExist(QString );
    static unsigned int CheckPasswordInDB(QString , QString);
    //void

};

#endif // USER_H
