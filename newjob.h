#ifndef NEWJOB_H
#define NEWJOB_H

#include <QMainWindow>

namespace Ui {
class NewJob;
}

class NewJob : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewJob(QString , QWidget *parent = nullptr);
    ~NewJob();

private slots:
    void on_pushButton_Create_clicked();

private:
    Ui::NewJob *ui;
    QString Username;
};

#endif // NEWJOB_H
