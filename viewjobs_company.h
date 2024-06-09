#ifndef VIEWJOBS_COMPANY_H
#define VIEWJOBS_COMPANY_H

#include <QWidget>

namespace Ui {
class ViewJobs_Company;
}

class ViewJobs_Company : public QWidget
{
    Q_OBJECT

public:
    explicit ViewJobs_Company(QString ,QWidget *parent = nullptr);
    ~ViewJobs_Company();

private slots:
    void on_pushButton_NewJob_clicked();

    void on_pushButton_nextJob_clicked();

    void on_pushButton_prevJob_clicked();

private:
    Ui::ViewJobs_Company *ui;
    QString Username;
    void ShowJobs();
    int JobCount;
    //void ShowApplys();
};

#endif // VIEWJOBS_COMPANY_H
