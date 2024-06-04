#ifndef ME_H
#define ME_H

#include "member.h"
#include <QMainWindow>

namespace Ui {
class Me;
}

class Me : public QMainWindow
{
    Q_OBJECT

public:
    explicit Me(QString , QWidget *parent = nullptr);
    ~Me();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_EditProfile_clicked();

    void on_pushButton_AreYouCompany_clicked();

private:
    Member * member;
    void ShowAreYouCompanyBut();
    void ShowImage();
    QString Username;
    bool IsCompany;
    void SetLabels();
    Ui::Me *ui;
};

#endif // ME_H
