#ifndef LIKE_H
#define LIKE_H
#include <QString>
#include <QDateTime>
class Like
{
    QString Username;
    unsigned int  Number;
    QDateTime TimeSent;
    QString TableName;
public:
    Like(QString,QString);
protected:
    //void SetTableName(QString);
    //void SetTimeSent();
    //void SetUsername(QString);
    //void SetNumber(unsigned int);
    QString GetUsername() const;
    unsigned int GetNumber() const;
    QString GetTimeSent() const;
    QString GetTableName() const;

};

#endif // LIKE_H
