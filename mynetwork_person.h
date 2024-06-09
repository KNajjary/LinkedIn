#ifndef MYNETWORK_PERSON_H
#define MYNETWORK_PERSON_H

#include <QWidget>

namespace Ui {
class MyNetwork_Person;
}

class MyNetwork_Person : public QWidget
{
    Q_OBJECT

public:
    explicit MyNetwork_Person(QWidget *parent = nullptr);
    ~MyNetwork_Person();

private:
    Ui::MyNetwork_Person *ui;
};

#endif // MYNETWORK_PERSON_H
