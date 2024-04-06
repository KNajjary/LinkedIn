#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include "LogAndSignInWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class WelcomeWindow;
}
QT_END_NAMESPACE

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();
    //void IsPushButton1Pressed();

private slots:
    void on_PushButton1_clicked();

private:
    Ui::WelcomeWindow *ui;
};
#endif // WELCOMEWINDOW_H
