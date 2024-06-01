#ifndef COMPLETECOMPANYINFO_H
#define COMPLETECOMPANYINFO_H

#include <QMainWindow>

namespace Ui {
class CompleteCompanyInfo;
}

class CompleteCompanyInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit CompleteCompanyInfo(QString , QWidget *parent = nullptr);
    ~CompleteCompanyInfo();

private slots:
    void on_pushButton_Done_clicked();

private:
    Ui::CompleteCompanyInfo *ui;
    QString Username;
};

#endif // COMPLETECOMPANYINFO_H
