#ifndef CONNECTIONREQICON_H
#define CONNECTIONREQICON_H

#include "person.h"
#include <QWidget>

namespace Ui {
class ConnectionReqIcon;
}

class ConnectionReqIcon : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionReqIcon(QString ,QString , QWidget *parent = nullptr);
    ~ConnectionReqIcon();

private slots:
    void on_pushButton_Accept_clicked();

    void on_pushButton_Ignore_clicked();

private:
    Ui::ConnectionReqIcon *ui;
    Person * RequestedPerson, * AcceptedPerson;

};

#endif // CONNECTIONREQICON_H
