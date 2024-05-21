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
