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
    explicit ViewJobs_Person(QString , QWidget *parent = nullptr);
    ~ViewJobs_Person();

private slots:
    void on_pushButton_next_clicked();

    void on_pushButton_prev_clicked();

    void on_pushButton_showAll_clicked();

private:
    Ui::ViewJobs_Person *ui;
    const QString JobsTable="Jobs",PersonUsername;
    QString Career;
    unsigned int JobLimit,JobNum;
};

#endif // VIEWJOBS_PERSON_H
