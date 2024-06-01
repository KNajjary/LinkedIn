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
