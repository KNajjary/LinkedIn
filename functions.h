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

#endif // FUNCTIONS_H
