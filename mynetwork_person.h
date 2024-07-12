#ifndef MYNETWORK_PERSON_H
#define MYNETWORK_PERSON_H

#include "person.h"
#include <QWidget>

namespace Ui {
class MyNetwork_Person;
}

class MyNetwork_Person : public QWidget
{
    Q_OBJECT

public:
    explicit MyNetwork_Person(QString ,QWidget *parent = nullptr);
    ~MyNetwork_Person();

private slots:
    void on_pushButton_nexSug_clicked();

    void on_pushButton_PrevSug_clicked();

    void on_pushButton_nextReq_clicked();

    void on_pushButton_pevReq_clicked();

private:
    Ui::MyNetwork_Person *ui;
    //QString Username;
    Person * person;
    unsigned int RequestsCount;
    void ShowRequests();
    void ShowSuggests();
};

#endif // MYNETWORK_PERSON_H
