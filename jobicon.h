#ifndef JOBICON_H
#define JOBICON_H

#include "job.h"
#include <QWidget>

namespace Ui {
class JobIcon;
}

class JobIcon : public QWidget
{
    Q_OBJECT

public:
    explicit JobIcon(QString,unsigned int,QString =NULL,QWidget *parent = nullptr);
    ~JobIcon();

    Job GetJob() const;

private slots:
    void on_pushButton_View_clicked();

private:
    Ui::JobIcon *ui;
    Job * job;
    QString PersonUsername;
};

#endif // JOBICON_H
