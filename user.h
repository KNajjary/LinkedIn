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

    //unsigned int NumOfPrevEmploymets;
    //unsigned int NumOfDegrees;
    Date BirthDate;
    Education EducationInfo;
    Job PrevEmploymet;
//protected:
    bool SetFirstNameInDB(QString);
    bool SetLastNameInDB(QString);
    bool SetPhoneInDB(QString);
    bool SetEmailInDB(QString);
    bool SetOver18InDB(bool);
    bool SetAddressCountryInDB(QString);
    bool SetAddressProvinceInDB(QString);
    bool SetAddressCityInDB(QString);
    bool SetIsStudentInDB(bool);
    bool SetBirthDateYearInDB(unsigned int);
    bool SetBirthDateMonthInDB(unsigned int);
    bool SetBirthDateDayInDB(unsigned int);

    bool SetEducationInfoMajorInDB(QString);
    bool SetEducationInfoSchoolNameInDB(QString);
    bool SetEducationInfoGradeInDB(QString);
    bool SetEducationInfoFinishedInDB(bool );
    bool SetEducationInfoStartYearInDB(unsigned  int);
    bool SetEducationInfoEndYearInDB(unsigned  int);

    bool SetPrevEmploymentCompanyNameInDB(QString);
    bool SetPrevEmploymentPostInDB(QString);
    bool SetPrevEmploymentEmploymentTipeInDB(QString);
    bool SetPrevEmploymentStartYearInDB(unsigned int);
    bool SetPrevEmploymentEndYearInDB(unsigned int);


    bool UpdateInDB(QString , unsigned int );
    bool UpdateInDB(QString , bool  );
    bool UpdateInDB(QString , QString  );

    static bool NameCheckValid(QString);
    static bool PhoneCheckValid(QString);
    static bool EmailCheckValid(QString);
    static bool MajorCheckValid(QString);
    static bool EmploymentTipeCheckValid(QString);
public:
    User(QString , QString);
    void AddToDB();
    bool SetFirstName(QString);
    bool SetLastName(QString);
    bool SetPhone(QString);
    bool SetEmail(QString);
    void SetOver18(bool);
    void SetAddressCountry(QString);
    void SetAddressProvince(QString);
    void SetAddressCity(QString);
    void SetIsStudent(bool);
    void SetBirthDateYear(unsigned int);
    void SetBirthDateMonth(unsigned int);
    void SetBirthDateDay(unsigned int);

    bool SetEducationInfoMajor(QString);
    void SetEducationInfoSchoolName(QString);
    void SetEducationInfoGrade(QString);
    void SetEducationInfoFinished(bool);
    void SetEducationInfoStartYear(unsigned int);
    void SetEducationInfoEndYear(unsigned int);

    void SetPrevEmploymentCompanyName(QString);
    void SetPrevEmploymentPost(QString);
    bool SetPrevEmploymentEmploymentTipe(QString);
    void SetPrevEmploymentStartYear(unsigned int);
    void SetPrevEmploymentEndYear(unsigned int);











    void SetLoggedIn(bool);
    static bool DoesUsernameExist(QString );
    static unsigned int CheckPasswordInDB(QString , QString);
    //void

};

#endif // USER_H
