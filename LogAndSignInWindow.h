#ifndef LOGANDSIGNINWINDOW_H
#define LOGANDSIGNINWINDOW_H

#include <QPropertyAnimation>
#include <QMainWindow>
#include "verificationwindow.h"
#include "completeuserinfowindow.h"
#include "user.h"
namespace Ui {
    class LogAndSignInWindow;
    //QString Password= NULL;
    //QString Username= NULL;
}

class LogAndSignInWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogAndSignInWindow(QWidget *parent = nullptr);
    ~LogAndSignInWindow();



private slots:
    void on_PushButton_LogIn_clicked();

    void on_pushButton_HaventSigned_clicked();

    void on_PushButton_Continue_clicked();

private:
    Ui::LogAndSignInWindow *ui;
    unsigned int CapchaCode;
    static QString Username,
        Password;
    //User user;
    friend class VerificationWindow  ;
    friend class CompleteUserInfoWindow;

    QPropertyAnimation * Animation;
};

#endif // LOGANDSIGNINWINDOW_H
