#include "message.h"
#include "ui_message.h"

Message::Message( QString text, QString im,QWidget *parent  )
    : QWidget(parent)
    , ui(new Ui::Message)
{
    ui->setupUi(this);
    SetText(text);
    SetPicture(im);


    //
    if(GetText().isEmpty()){
        //ui->label_Text->hide();
        ui->textBrowser->hide();
    }
    else ui->textBrowser->setPlainText(GetText());
    //
    if(GetPicture().isEmpty()){
        ui->label_Image->hide();
    }
    else{
        QPixmap Im(GetPicture());
        int LabelH=ui->label_Image->height();
        int LabelW=ui->label_Image->width();
        ui->label_Image->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatio));
    }

    //
    ui->label_Time->setText(GetTimeSent());
}

Message::~Message()
{
    delete ui;
}
