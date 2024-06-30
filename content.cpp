#include "content.h"
QString Content::GetTimeSent()const
{
    return TimeSent.toString();
}
QString Content::GetText()const
{
    return Text;
}
QString Content::GetPicture()const
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
unsigned int Content::GetNumber()const
{
    return Number;
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
QString Content::GetSenderUsername()const
{
    return SenderUsername;
}
void Content::SetTableName(QString t)
{
    TableName = t;
}
QString Content::GetTableName() const
{
    return TableName;
}
void Content::SetNumber(unsigned int n)
{
    Number=n;
}
void Content::SetTimeSent(const QDateTime t){
    TimeSent=t;
}
