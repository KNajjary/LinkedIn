#include "viewjobs_person.h"
#include "ui_viewjobs_person.h"

ViewJobs_Person::ViewJobs_Person(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewJobs_Person)
{
    ui->setupUi(this);
}

ViewJobs_Person::~ViewJobs_Person()
{
    delete ui;
}
