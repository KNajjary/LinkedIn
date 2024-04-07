#ifndef VERIFICATIONWINDOW_H
#define VERIFICATIONWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "completeuserinfowindow.h"
namespace Ui {
class VerificationWindow;
}
//extern QString Password;
//extern QString Username;
class VerificationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VerificationWindow(QWidget *parent = nullptr);
    ~VerificationWindow();

private slots:
    void on_pushButton_SendCode_clicked();

    void on_pushButton_SignIn_clicked();

private:
    Ui::VerificationWindow *ui;
    unsigned int VerifCode;
    //User * User;
    //friend CompleteUserInfoWindow;
};

#endif // VERIFICATIONWINDOW_H
