#ifndef CONTENT_H
#define CONTENT_H
#include <QDateTime>
class Content
{
    QString SenderUsername;
    QString ID;
    QDateTime TimeSent;
    QString Text;
    QString Picture;
    QString TableName;
public:
    //
    //Content();


protected:
    void SetTableName(QString);
    void SetText(QString);
    void SetPicture(QString);
    void SetTimeSent();
    void SetSenderUsername(QString);
    QString GetSenderUsername();
    QString GetID();
    QString GetTimeSent();
    QString GetText();
    QString GetPicture();
    QString GetTableName();
};

#endif // CONTENT_H
