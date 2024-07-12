#ifndef ROOT_H
#define ROOT_H

#include "home.h"
#include "me.h"
#include "mynetwork_company.h"
#include "mynetwork_person.h"
#include "viewjobs_company.h"
#include "viewjobs_person.h"
#include <QMainWindow>

namespace Ui {
class Root;
}

class Root : public QMainWindow
{
    Q_OBJECT

public:
    explicit Root(QString,QWidget *parent = nullptr);
    ~Root();

private slots:
    void on_pushButton_Home_clicked();

    void on_pushButton_MyNetw_clicked();

    void on_pushButton_Jobs_clicked();

    void on_pushButton_Messaging_clicked();

    void on_pushButton_Me_clicked();

    void on_pushButton_Reload_clicked();

    void on_pushButton_Search_clicked();

private:
    Ui::Root *ui;
    QString ViewerUsername;
    bool IsViewerACompany;
    Home * HomeP;
    Me * MeP;
    MyNetwork_Company * MyNetwork_CompanyP;
    MyNetwork_Person * MyNetwork_PersonP;
    ViewJobs_Company * ViewJobs_CompanyP;
    ViewJobs_Person * ViewJobs_PersonP;
    void SetAllButtonsUnclicked();


};

#endif // ROOT_H
