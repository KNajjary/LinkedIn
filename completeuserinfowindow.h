#ifndef COMPLETEUSERINFOWINDOW_H
#define COMPLETEUSERINFOWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "LogAndSignInWindow.h"
namespace Ui {
class CompleteUserInfoWindow;
}
//extern QString Password;
//extern QString Username;
class CompleteUserInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CompleteUserInfoWindow(QString , QWidget *parent = nullptr);
    ~CompleteUserInfoWindow();
    //void SetUser(User *);
    //const User*  GetUser(void);
    void Hide_pushButton_AreYouCompany();

private slots:
    void on_pushButton_Done_clicked();



    //void on_pushButton_AdEdu_clicked();

    //void on_pushButton_AddPo_clicked();



    void on_pushButton_AreYouCompany_clicked();

private:
    QString Username;
    Ui::CompleteUserInfoWindow *ui;
    //User * User;
};

#endif // COMPLETEUSERINFOWINDOW_H
