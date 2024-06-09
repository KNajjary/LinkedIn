#include "mynetwork_person.h"
#include "ui_mynetwork_person.h"

MyNetwork_Person::MyNetwork_Person(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyNetwork_Person)
{
    ui->setupUi(this);
}

MyNetwork_Person::~MyNetwork_Person()
{
    delete ui;
}
