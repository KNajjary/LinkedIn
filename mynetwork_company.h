#ifndef MYNETWORK_COMPANY_H
#define MYNETWORK_COMPANY_H

#include "company.h"
#include <QWidget>

namespace Ui {
class MyNetwork_Company;
}

class MyNetwork_Company : public QWidget
{
    Q_OBJECT

public:
    explicit MyNetwork_Company(QString,QWidget *parent = nullptr);
    ~MyNetwork_Company();

private slots:
    void on_pushButton_next_clicked();

    void on_pushButton_prev_clicked();

private:
    Ui::MyNetwork_Company *ui;
    //QString Username;
    Company * company;
};

#endif // MYNETWORK_COMPANY_H
