#include "like.h"
#include "mydatabase.h"

Like::Like(QString table, QString u)
{
    Username=u;
    TableName=table;
    TimeSent=QDateTime::currentDateTime();
    MyDatabase db;
    db.InsertLike(TableName,Username,TimeSent.toString());
    Number = db.GetNumberOfRows(TableName);

}
QString Like::GetUsername() const
{
    return Username;
}
unsigned int Like::GetNumber() const
{
    return Number;
}
QString Like::GetTimeSent() const
{
    return TimeSent.toString();
}
QString Like::GetTableName() const
{
    return TableName;
}
