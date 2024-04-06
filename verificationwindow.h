#ifndef VERIFICATIONWINDOW_H
#define VERIFICATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class VerificationWindow;
}

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
};

#endif // VERIFICATIONWINDOW_H
