#ifndef APPLYVIEW_H
#define APPLYVIEW_H

#include "person.h"
#include <QWidget>

namespace Ui {
class ApplyView;
}

class ApplyView : public QWidget
{
    Q_OBJECT

public:
    explicit ApplyView(QString table,unsigned int n,QWidget *parent = nullptr);
    ~ApplyView();

private slots:
    void on_pushButton_Accept_clicked();

    void on_pushButton_Ignore_clicked();

private:
    Ui::ApplyView *ui;
    Person *person;
    QString ApplyTable;
    QString Username;
};

#endif // APPLYVIEW_H
