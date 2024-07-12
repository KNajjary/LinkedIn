#include "comment.h"
#include "ui_comment.h"
#include "mydatabase.h"
Comment::Comment(QString table,QString owner,QString user,QString text,QString pic, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Comment)
{
    ui->setupUi(this);
    //
    TableName=table;
    SetText(text);
    SetPicture(pic);
    SetTimeSent();
    SetSenderUsername(user);
    //
    MyDatabase db;
    db.CreateCommentTable(TableName);
    db.InsertComment(TableName,owner,GetSenderUsername(),GetText(),GetPicture(),GetTimeSent());
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
        ui->label_Image->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatioByExpanding));
    }
}
Comment::Comment(QString table, unsigned int number,QWidget *parent )
    : QWidget(parent)
    , ui(new Ui::Comment)
{
    ui->setupUi(this);
    //
    RowNumber=number;
    TableName =table;
    MyDatabase db;
    SetText(db.SelectWhere(TableName,"RowNumber",RowNumber,"Text",1));
    SetPicture(db.SelectWhere(TableName,"RowNumber",RowNumber,"Picture",1));
    SetTimeSent(QDateTime::fromString(db.SelectWhere(TableName,"RowNumber",RowNumber,"TimeSent",1)));
    SetSenderUsername(db.SelectWhere(TableName,"RowNumber",RowNumber,"Username",1));
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
        ui->label_Image->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatioByExpanding));
    }


}

Comment::~Comment()
{
    delete ui;
}
