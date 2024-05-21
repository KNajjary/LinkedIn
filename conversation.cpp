#include "conversation.h"
#include "ui_conversation.h"
#include "message.h"
Conversation::Conversation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Conversation)
{
    ui->setupUi(this);
}

Conversation::~Conversation()
{
    delete ui;
}

void Conversation::on_pushButton_send_clicked()
{
    //if(ui->lineEdit_text->text().isEmpty() && )return;
    Message * m= new Message(ui->textEdit_text->toPlainText());
    ui->verticalLayout_messages->addWidget(m);

}


void Conversation::on_pushButton_chooseImage_clicked()
{

}

