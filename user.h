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
//protected:
    bool SetFirstNameInDB(QString);
    bool SetLastNameInDB(QString);
    bool SetPhoneInDB(QString);
    bool SetEmailInDB(QString);
    bool SetOver18InDB(bool);
    bool SetAddress_CountryInDB(QString);
    bool SetAddress_ProvinceInDB(QString);
    bool SetAddress_CityInDB(QString);
    bool SetIsStudentInDB(bool);
    bool SetBirthDate_YearInDB(unsigned short);
    bool SetBirthDate_MonthInDB(unsigned short);
    bool SetBirthDate_DayInDB(unsigned short);
public:
    User(QString , QString);
    void AddToDB();

    bool SetFirstName(QString);
    bool SetLastName(QString);
    bool SetPhone(QString);
    bool SetEmail(QString);
    void SetOver18(bool);
    void SetAddress_Country(QString);
    void SetAddress_Province(QString);
    void SetAddress_City(QString);
    void SetIsStudent(bool);
    void SetBirthDate_Year(unsigned short);
    void SetBirthDate_Month(unsigned short);
    void SetBirthDate_Day(unsigned short);

    static bool NameCheckValid(QString);
    static bool PhoneCheckValid(QString);
    static bool EmailCheckValid(QString);
    static bool MajorCheckValid(QString);
    static bool EmploymentTipeCheckValid(QString);








    void SetLoggedIn(bool);
    static bool DoesUsernameExist(QString );
    static unsigned int CheckPasswordInDB(QString , QString);
    //void

};

#endif // USER_H
