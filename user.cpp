#include "user.h"
#include "functions.h"
//#include <QDebug>

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include <QSqlError>
/*
 QSqlDatabase database;
database = QSqlDatabase::addDatabase("QSQLITE");
database.setDatabaseName("d:\\Linked In\\LinkedIn.db");
database.open():
*/
User::User(QString na,QString pa)
{
    Username=na;
    Password=pa;

}
void User::AddToDB(){
    if(Username.isEmpty() || Password.isEmpty()){
        qDebug()<< "Wrong place to call AddToDB function";
        return;
    }
    QSqlDatabase database;
    SetupDatabase(database);

    QSqlQuery qr;
    qr.prepare("INSERT INTO Users ("
               "Username,"
               "Password)"
               "VALUES (?,?);");
    qr.addBindValue(Username);
    qr.addBindValue(Password);

    if(!qr.exec()){
        qDebug() << "error adding values to User table in database" ;
    }


    CloseDatabase(database);
    return;
}
void User::SetLoggedIn(bool state){
    LoggedIn=state;


}
bool User::DoesUsernameExist(QString un){
    QSqlDatabase database;
    SetupDatabase(database);
    bool found=false;
    QSqlQuery qr;
    qr.exec();
    qr.exec("SELECT * FROM Users WHERE Username='"+un+"'");
    if(qr.first())found=true;


    CloseDatabase(database);
    if(found)return true;
    else return false;
}
unsigned int User::CheckPasswordInDB(QString un, QString p){
    //0 means password is incorrect
    //1 means password is correct
    //2 means username does not exist

    unsigned int state=3;
    if (!DoesUsernameExist(un))  state=2;
    else {
        QSqlDatabase database;
        SetupDatabase(database);
        QSqlQuery qr;

        qr.exec("SELECT Password FROM Users WHERE Username='"+un+"'");
        qr.first();
        if(qr.value(0).toString() == p){
            state=1;
        }
        else{
            state=0;
        }
        CloseDatabase(database);
    }

    return state;
}
/*bool result=true;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    qr.exec("SELECT FirstName FROM Users WHERE Username='"+Username+"'");

    qr.first();
    qr.value(0).setValue(&n);
    //"INSERT INTO Users ( FirstName ) VALUES (?) WHERE Username = ? ;"

    if (! qr.prepare("UPDATE Users SET FirstName = ? WHERE Username = ? ;"))
    {
       qDebug() << "Query preparation failed:" << qr.lastError().text();

    }
    else{
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(! qr.exec()){
            result=false;
            //QSqlError er = ;

            qDebug() << "##Error"<< "Query execution failed:" << qr.lastError().text();

        }
    }



    qr.prepare("UPDATE Users SET FirstName = :n WHERE Username = :u ;");
    //qr.isValid();
    qr.bindValue(":n", n);

    qr.bindValue(":u",Username);

    qr.prepare("UPDATE Users SET FirstName = '"+n+"' WHERE Username = '"+Username+"' ;");
    //qr.isValid();
    qr.addBindValue(n);

    qr.addBindValue(Username);


    CloseDatabase(database);
    return result;*/
bool User::SetFirstNameInDB(QString n){
    return UpdateInDB("FirstName" , n);
}
bool User::SetLastNameInDB(QString n){
    return UpdateInDB("LastName" , n);
}
bool User::SetPhoneInDB(QString s) {
    return UpdateInDB("Phone" , s);
}
bool User::SetEmailInDB(QString n){
    return UpdateInDB("Email" , n);
}
bool User::SetAddressCountryInDB(QString n){
    return UpdateInDB("AddressCountry" , n);
}
bool User::SetAddressProvinceInDB(QString n){
    return UpdateInDB("AddressProvince" , n);
}
bool User::SetAddressCityInDB(QString n){
    return UpdateInDB("AddressCity" , n);
}
bool User::SetOver18InDB(bool b){
    return UpdateInDB("Over18", b);
}
bool User::SetIsStudentInDB(bool b){
    return UpdateInDB("IsStudent", b);
}
bool User::SetBirthDateYearInDB(unsigned  int n){
    return UpdateInDB("BirthDateYear", n);
}
bool User::SetBirthDateMonthInDB(unsigned  int  n){
    return UpdateInDB("BirthDateMonth", n);
}
bool User::SetBirthDateDayInDB(unsigned  int n){
    return UpdateInDB("BirthDateDay", n);
}
bool User::SetEducationInfoMajorInDB(QString s){
    return UpdateInDB("EducationInfoMajor", s);
}
bool User::SetEducationInfoSchoolNameInDB(QString s){
    return UpdateInDB("EducationInfoSchoolName" , s);
}
bool User::SetEducationInfoGradeInDB(QString s){
    return UpdateInDB("EducationInfoGrade", s);
}
bool User::SetEducationInfoFinishedInDB(bool b){
    return UpdateInDB("EducationInfoFinished", b);
}
bool User::SetEducationInfoStartYearInDB(unsigned  int n){
    return UpdateInDB("EducationInfoStartYear", n);
}
bool User::SetEducationInfoEndYearInDB(unsigned  int n){
    return UpdateInDB("EducationInfoEndYear", n);
}
bool  User::SetPrevEmploymentCompanyNameInDB(QString s){
    return UpdateInDB("PrevEmploymentCompanyName", s);
}
bool  User::SetPrevEmploymentPostInDB(QString s){
    return UpdateInDB("PrevEmploymentPost", s);
}
bool  User::SetPrevEmploymentEmploymentTipeInDB(QString s){
    return UpdateInDB("PrevEmploymentEmploymentTipe", s);
}

bool  User::SetPrevEmploymentStartYearInDB(unsigned int n ){
    return UpdateInDB("PrevEmploymentStartYear", n);
}
bool  User::SetPrevEmploymentEndYearInDB(unsigned int n){
    return UpdateInDB("PrevEmploymentEndYear", n);
}
bool User::UpdateInDB(QString f,QString  v)
{
    bool result=false;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET "+ f +  " = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(v);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
        else qDebug()<< "Query execution failed: " << qr.lastError().text();
    }
    else qDebug()<< "Query execution failed: " << qr.lastError().text();
    CloseDatabase(database);
    return result;
}
bool User::UpdateInDB(QString f,unsigned int  v){
    bool result=false;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET "+ f +  " = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(v);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
        else qDebug()<< "Query execution failed: " << qr.lastError().text();
    }
    else qDebug()<< "Query execution failed: " << qr.lastError().text();
    CloseDatabase(database);
    return result;
}
bool User::UpdateInDB(QString f, bool v){
    bool result=false;
    unsigned int n;
    if(v)n=1;
    else n=0;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET "+ f + " = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
        else qDebug()<< "Query execution failed: " << qr.lastError().text();
    }
    else qDebug()<< "Query execution failed: " << qr.lastError().text();
    CloseDatabase(database);
    return result;
}



bool User::SetFirstName(QString n){
    if(!NameCheckValid(n))
        return false;

    FirstName=n;
    if(! SetFirstNameInDB(n))
        qDebug()<< "error updating FirstName in data base."  ;
    return true;
}

bool User::SetLastName(QString n){
    if(!NameCheckValid(n))
        return false;

    LastName=n;
    if(! SetLastNameInDB(n))
        qDebug()<< "error updating LastName in data base." ;
    return true;
}

bool User::SetPhone(QString s){
    if(! PhoneCheckValid(s))
        return false;
    Phone=s;
    if(! SetPhoneInDB(s))
        qDebug()<< "error updating Phone in data base." ;
    return true;

}
bool User::SetEmail(QString s){

    if(! EmailCheckValid(s))
        return false;
    Email=s;
    if(! SetEmailInDB(s))
        qDebug()<< "error updating Email in data base." ;
    return true;

}
void User::SetOver18(bool b){
    Over18=b;
    if(! SetOver18InDB(b))
        qDebug()<< "error updating Over18 in data base." ;

}

void User::SetIsStudent(bool b){
    IsStudent=b;
    if(! SetIsStudentInDB(b))
        qDebug()<< "error updating IsStudent in data base." ;
}
void User::SetAddressCountry(QString a){
    Address.Country=a;
    if(! SetAddressCountryInDB(a))
        qDebug()<< "error updating Address.Country in data base." ;
}
void User::SetAddressProvince(QString a){
    Address.Province=a;
    if(! SetAddressProvinceInDB(a))
        qDebug()<< "error updating Address.Province in data base." ;
}
void User::SetAddressCity(QString a){
    Address.City=a;
    if(! SetAddressCityInDB(a))
        qDebug()<< "error updating Address.City in data base." ;
}
void User::SetBirthDateYear(unsigned int b){
    BirthDate.Year= b;
    if(! SetBirthDateYearInDB(b))
        qDebug()<< "error updating BirthDate.Year in data base." ;
}
void User::SetBirthDateMonth(unsigned int b){
    BirthDate.Month= b;
    if(! SetBirthDateMonthInDB(b))
        qDebug()<< "error updating BirthDate.Month in data base." ;
}
void User::SetBirthDateDay(unsigned int b){
    BirthDate.Day= b;
    if(! SetBirthDateDayInDB(b))
        qDebug()<< "error updating BirthDate.Day in data base." ;
}
bool User::SetEducationInfoMajor(QString s){
    if(! MajorCheckValid(s))
        return false;
    EducationInfo.Major = s;
    if(! SetEducationInfoMajorInDB(s))
        qDebug()<< "error updating EducationInfoMajor in data base." ;
    return true;
}
void User::SetEducationInfoSchoolName(QString s){
    EducationInfo.SchoolName = s;
    SetEducationInfoSchoolNameInDB(s);
}
void User::SetEducationInfoGrade(QString s){
    EducationInfo.Grade = s;
    SetEducationInfoGradeInDB(s);
}
void User::SetEducationInfoFinished(bool b){
    EducationInfo.Finished = b;
    SetEducationInfoFinishedInDB(b);
}
void User::SetEducationInfoStartYear(unsigned  int n){
    EducationInfo.StartYear = n;
    SetEducationInfoStartYearInDB(n);
}
void User::SetEducationInfoEndYear(unsigned int n){
    EducationInfo.EndYear = n;
    SetEducationInfoEndYearInDB(n);
}
void User::SetPrevEmploymentCompanyName(QString s){
    PrevEmploymet.CompanyName = s;
    SetPrevEmploymentCompanyNameInDB(s);
}
void User::SetPrevEmploymentPost(QString s){
    PrevEmploymet.Post = s;
    SetPrevEmploymentPostInDB(s);
}
bool User::SetPrevEmploymentEmploymentTipe(QString s){
    if(! EmploymentTipeCheckValid(s))
        return false;
    PrevEmploymet.EmploymentTipe =s ;
    SetPrevEmploymentEmploymentTipeInDB(s);
    return true;
}
void User::SetPrevEmploymentStartYear(unsigned int n){
    PrevEmploymet.StartYear = n;
    SetPrevEmploymentStartYearInDB(n);
}
void User::SetPrevEmploymentEndYear(unsigned int n){
    PrevEmploymet.EndYear = n;
    SetPrevEmploymentEndYearInDB(n);
}
bool User::NameCheckValid(QString s)
{
    if(IsMadeOfLetters(s)) return true;
    else return false;
}
 bool User::PhoneCheckValid(QString s)
{
     if(IsMadeOfNumbers(s)) return true;
     else return false;
}
bool User::EmailCheckValid(QString s)
{
    std::string a=s.toStdString();
    unsigned int i;
    bool DotFound =false,AtsFound =false;//.  @
    for(i=0;a[i] ;i++){
        if(a[i]== '@')AtsFound=true;
        if(a[i]=='.')DotFound=true;
    }
    if( DotFound && AtsFound)return true;
    else return false;
}
bool User::MajorCheckValid(QString s)
{
    if(IsMadeOfLetters(s)) return true;
    else return false;
}
bool User::EmploymentTipeCheckValid(QString s)
{
    if(IsMadeOfLetters(s)) return true;
    else return false;
}

