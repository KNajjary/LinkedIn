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

private slots:
    void on_pushButton_ViewProf_clicked();

    void on_pushButton_ConFol_clicked();

private:
    Ui::ProfileIcon *ui;
    Member * member,* me;
    QString PersonUsername,MyUsername;
    bool IsPerson,IAmCompany;
};

#endif // PROFILEICON_H
