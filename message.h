#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include "content.h"
namespace Ui {
class Message;
}

class Message : public QWidget, public Content
{
    Q_OBJECT

public:
    explicit Message(QString , QString = nullptr , QWidget *parent = nullptr);
    ~Message();

private:
    Ui::Message *ui;
};

#endif // MESSAGE_H
