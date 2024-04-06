#include "functions.h"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

#include "QMessageBox"

void SetupDatabase(QSqlDatabase database)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\Linked In\\LinkedIn.db");
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
