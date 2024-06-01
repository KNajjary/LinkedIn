#include "content.h"
QString Content::GetTimeSent()
{
    return TimeSent.toString();
}
QString Content::GetText()
{
    return Text;
}
QString Content::GetPicture()
{
    return Picture;
}
void Content::SetText(QString t)
{
    Text=t;
}
void Content::SetPicture(QString p)
{
    Picture=p;
}
void Content::SetTimeSent()
{
    TimeSent=QDateTime::currentDateTime();
}
QString Content::GetID()
{
    return ID;
}
/*Content::Content()
{
   //username
   TimeSent=QDateTime::currentDateTime();
   //ID

}*/
void Content::SetSenderUsername(QString u)
{
    SenderUsername=u;
}
QString Content::GetSenderUsername()
{
    return SenderUsername;
}
void Content::SetTableName(QString t)
{
    TableName = t;
}
QString Content::GetTableName()
{
    return TableName;
}
