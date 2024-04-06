#ifndef COMPLETEUSERINFOWINDOW_H
#define COMPLETEUSERINFOWINDOW_H

#include <QMainWindow>
#include "user.h"
namespace Ui {
class CompleteUserInfoWindow;
}

class CompleteUserInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CompleteUserInfoWindow( QWidget *parent = nullptr);
    ~CompleteUserInfoWindow();
    void SetUser(User*);
    const User*  GetUser(void);

private slots:
    void on_pushButton_Done_clicked();

private:
    Ui::CompleteUserInfoWindow *ui;
    User* user;
};

#endif // COMPLETEUSERINFOWINDOW_H
