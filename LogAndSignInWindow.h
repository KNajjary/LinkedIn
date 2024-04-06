#ifndef LOGANDSIGNINWINDOW_H
#define LOGANDSIGNINWINDOW_H

#include <QMainWindow>
#include "verificationwindow.h"
namespace Ui {
class LogAndSignInWindow;
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
    friend VerificationWindow;
};

#endif // LOGANDSIGNINWINDOW_H
