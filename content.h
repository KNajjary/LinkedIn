#ifndef CONTENT_H
#define CONTENT_H
#include <QDateTime>
class Content
{
    QString SenderUsername;
    unsigned int  Number;
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
    void SetTimeSent(const QDateTime);
    void SetSenderUsername(QString);
    void SetNumber(unsigned int);
    //------------------
    QString GetSenderUsername()const;
    unsigned int GetNumber()const;
    QString GetTimeSent()const;
    QString GetText()const;
    QString GetPicture()const;
    QString GetTableName()const;
};

#endif // CONTENT_H
