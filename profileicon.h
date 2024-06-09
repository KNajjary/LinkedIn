#ifndef PROFILEICON_H
#define PROFILEICON_H

#include "member.h"
#include <QWidget>

namespace Ui {
class ProfileIcon;
}

class ProfileIcon : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileIcon(QString,QString,QWidget *parent = nullptr);
    ~ProfileIcon();

private:
    Ui::ProfileIcon *ui;
    Member * member;
    QString PersonUsername;
    bool IsPerson,IAmCompany;
};

#endif // PROFILEICON_H
