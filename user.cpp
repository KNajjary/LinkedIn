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
bool User::SetFirstNameInDB(QString n){
    bool result=true;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    /*qr.exec("SELECT FirstName FROM Users WHERE Username='"+Username+"'");

    qr.first();
    qr.value(0).setValue(&n);*/
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



    /*qr.prepare("UPDATE Users SET FirstName = :n WHERE Username = :u ;");
    //qr.isValid();
    qr.bindValue(":n", n);

    qr.bindValue(":u",Username);

    qr.prepare("UPDATE Users SET FirstName = '"+n+"' WHERE Username = '"+Username+"' ;");
    //qr.isValid();
    qr.addBindValue(n);

    qr.addBindValue(Username);*/


    CloseDatabase(database);
    return result;
}
bool User::SetLastNameInDB(QString n){
    bool result=true;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (! qr.prepare("UPDATE Users SET LastName = ? WHERE Username = ? ;"))
    {
        qDebug() << "in function User::SetLastName : Query preparation failed :" << qr.lastError().text();

    }
    else{
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(! qr.exec()){
            result=false;
            //QSqlError er = ;

            qDebug() <<  "in function User::SetLastName : Query execution failed:" << qr.lastError().text();

        }
    }
    CloseDatabase(database);
    return result;
}
bool User::SetPhoneInDB(QString s) {
    bool result=true;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (! qr.prepare("UPDATE Users SET Phone = ? WHERE Username = ? ;"))
    {
        qDebug() << "in function User::SetPhone : Query preparation failed :" << qr.lastError().text();

    }
    else{
        qr.addBindValue(s);
        qr.addBindValue(Username);
        if(! qr.exec()){
            result=false;
            //QSqlError er = ;

            qDebug() <<  "in function User::SetPhone : Query execution failed:" << qr.lastError().text();

        }
    }
    CloseDatabase(database);
    return result;
}
bool User::SetEmailInDB(QString n){
    bool result=false;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET Email = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
    }
    CloseDatabase(database);
    return result;
}
bool User::SetOver18InDB(bool b){
    bool result=false;
    unsigned int n;
    if(b)n=1;
    else n=0;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET Over18 = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
    }
    CloseDatabase(database);
    return result;
}
bool User::SetAddress_CountryInDB(QString n){
    bool result=false;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET Address.Country = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
    }
    CloseDatabase(database);
    return result;
}
bool User::SetAddress_ProvinceInDB(QString n){
    bool result=false;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET Address.Province = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
    }
    CloseDatabase(database);
    return result;
}
bool User::SetAddress_CityInDB(QString n){
    bool result=false;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET Address.City = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
    }
    CloseDatabase(database);
    return result;
}
bool User::SetIsStudentInDB(bool b){
    bool result=false;
    unsigned int n;
    if(b)n=1;
    else n=0;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET IsStudent = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
    }
    CloseDatabase(database);
    return result;
}
bool User::SetBirthDate_YearInDB(unsigned short n){
    bool result=false;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET BirthDate.Year = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
    }
    CloseDatabase(database);
    return result;
}
bool User::SetBirthDate_MonthInDB(unsigned short n){
    bool result=false;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET BirthDate.Month = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
    }
    CloseDatabase(database);
    return result;
}
bool User::SetBirthDate_DayInDB(unsigned short n){
    bool result=false;
    QSqlDatabase database;
    SetupDatabase(database);
    QSqlQuery qr;
    if (qr.prepare("UPDATE Users SET BirthDate.Day = ? WHERE Username = ? ;"))
    {
        qr.addBindValue(n);
        qr.addBindValue(Username);
        if(qr.exec())
            result=true;
    }
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
    Email=s;
    if(! EmailCheckValid(s))
        return false;
    Phone=s;
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
void User::SetAddress_Country(QString a){
    Address.Country=a;
    if(! SetAddress_CountryInDB(a))
        qDebug()<< "error updating Address.Country in data base." ;
}
void User::SetAddress_Province(QString a){
    Address.Province=a;
    if(! SetAddress_ProvinceInDB(a))
        qDebug()<< "error updating Address.Province in data base." ;
}
void User::SetAddress_City(QString a){
    Address.City=a;
    if(! SetAddress_CityInDB(a))
        qDebug()<< "error updating Address.City in data base." ;
}
void User::SetBirthDate_Year(unsigned short int b){
    BirthDate.Year= b;
    if(! SetBirthDate_YearInDB(b))
        qDebug()<< "error updating BirthDate.Year in data base." ;
}
void User::SetBirthDate_Month(unsigned short b){
    BirthDate.Month= b;
    if(! SetBirthDate_MonthInDB(b))
        qDebug()<< "error updating BirthDate.Month in data base." ;
}
void User::SetBirthDate_Day(unsigned short b){
    BirthDate.Day= b;
    if(! SetBirthDate_DayInDB(b))
        qDebug()<< "error updating BirthDate.Day in data base." ;
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

