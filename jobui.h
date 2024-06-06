#ifndef JOBUI_H
#define JOBUI_H

#include "job.h"
#include <QWidget>

namespace Ui {
class JobUi;
}

class JobUi : public QWidget , public Job
{
    Q_OBJECT

public:
    explicit JobUi(QString , unsigned int , QString, QWidget *parent = nullptr);
    ~JobUi();

private slots:
    void on_pushButton_apply_clicked();

private:
    Ui::JobUi *ui;
    QString PersonUsername;
    void SetLabels();
    void SetButton();
};

#endif // JOBUI_H
