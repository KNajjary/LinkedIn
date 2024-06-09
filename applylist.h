#ifndef APPLYLIST_H
#define APPLYLIST_H

#include <QWidget>

namespace Ui {
class ApplyList;
}

class ApplyList : public QWidget
{
    Q_OBJECT

public:
    explicit ApplyList(QString,unsigned int,QWidget *parent = nullptr);
    ~ApplyList();

private:
    Ui::ApplyList *ui;
    QString Table;
};

#endif // APPLYLIST_H
