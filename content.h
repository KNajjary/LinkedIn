#ifndef CONTENT_H
#define CONTENT_H
#include <QDateTime>
class Content
{
    QString SenderUsername;
    QDateTime TimeSent;
    QString Text;
    QString Picture;
public:
    //Content();


protected:
    void SetText(QString);
    void SetPicture(QString);
    void SetTimeSent();
    QString GetTimeSent();
    QString GetText();
    QString GetPicture();

};

#endif // CONTENT_H
