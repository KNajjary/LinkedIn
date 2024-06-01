#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void SetupDatabase(QSqlDatabase);
void CloseDatabase(QSqlDatabase);
bool IsMadeOfLetters(QString );
bool IsMadeOfNumbers(QString );
bool IsEmailValid(QString);
#endif // FUNCTIONS_H
