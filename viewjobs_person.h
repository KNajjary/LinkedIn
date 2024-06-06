#ifndef VIEWJOBS_PERSON_H
#define VIEWJOBS_PERSON_H

#include <QMainWindow>

namespace Ui {
class ViewJobs_Person;
}

class ViewJobs_Person : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewJobs_Person(QWidget *parent = nullptr);
    ~ViewJobs_Person();

private:
    Ui::ViewJobs_Person *ui;
};

#endif // VIEWJOBS_PERSON_H
