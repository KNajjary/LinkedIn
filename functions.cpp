#include "functions.h"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

#include "QMessageBox"

void SetupDatabase(QSqlDatabase database)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:\\Linked In\\LinkedIn\\LinkedIn.db");
    database.open();

}
void CloseDatabase(QSqlDatabase db)
{
    db.close();

}
/*void SearchForUserInDB(QString na, QString pa)
{
    QSqlDatabase database;
    SetupDatabase(database);

    QSqlQuery qr;
    qr.exec("SELECT Password FROM Users WHERE Username='"+na+"'");
    if(qr.first()){

    }
    else{
        QMessageBox::warning(this,"","");
    }



    CloseDatabase(database);
}*/
bool IsMadeOfLetters(QString s){
    std::string a=s.toStdString();
    unsigned int i;
    for(i=0;a[i] && ((a[i]>= 'a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') );i++);
    if(!a[i])return true;
    else return false;
}
bool IsMadeOfNumbers(QString s){
    std::string a=s.toStdString();
    unsigned int i;
    for(i=0;a[i] && a[i]>= '0' && a[i]<='9'  ;i++);
    if(!a[i])return true;
    else return false;
}
bool IsEmailValid(QString s)
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
