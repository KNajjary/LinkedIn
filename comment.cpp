#include "comment.h"
#include "ui_comment.h"
#include "mydatabase.h"
Comment::Comment(QString table,QString user,QString text,QString pic, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Comment)
{
    ui->setupUi(this);
    TableName=table;
    SetText(text);
    SetPicture(pic);
    SetTimeSent();
    SetSenderUsername(user);
    //
    MyDatabase db;
    db.InsertComment(TableName,GetSenderUsername(),GetText(),GetPicture(),GetTimeSent());
    //
    ui->label_Username->setText(GetSenderUsername());
    ui->label_Time->setText(GetTimeSent());
    if(GetText().isEmpty())
        ui->textBrowser->hide();
    else
        ui->textBrowser->setText(GetText());
    if(GetPicture().isEmpty())
        ui->label_Image->hide();
    else{
        QPixmap Im(GetPicture());
        int LabelW,LabelH;
        LabelH=ui->label_Image->height();
        LabelW=ui->label_Image->width();
        ui->label_Image->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatio));
    }
}

Comment::~Comment()
{
    delete ui;
}
