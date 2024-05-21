#ifndef CONVERSATION_H
#define CONVERSATION_H

//#include <QWidget>
#include <QMainWindow>
#include "message.h"
namespace Ui {
class Conversation;
}

class Conversation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Conversation(QWidget *parent = nullptr);
    ~Conversation();

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_chooseImage_clicked();

private:
    Ui::Conversation *ui;
    QString SecondUsername;
    //std::vector <Message> Messages;
};

#endif // CONVERSATION_H
