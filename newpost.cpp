#include "newpost.h"
#include "post.h"
#include "ui_newpost.h"

#include <QFileDialog>

NewPost::NewPost(QString u, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewPost)
{
    ui->setupUi(this);
    ImageAddress=nullptr;
    ui->label_Image->hide();
    Username= u;
}

NewPost::~NewPost()
{
    delete ui;
}

void NewPost::on_pushButton_selectImage_clicked()
{
    ui->label_Image->hide();
    ImageAddress = QFileDialog::getOpenFileName(
        this,
        "Choose picture",
        "D://Linked In//images",
        "Image File (*.png);;Image File (*.jpg);;");
    if(!ImageAddress.isEmpty()){
        QPixmap Im(ImageAddress);
        int LabelW,LabelH;
        LabelH=ui->label_Image->height();
        LabelW=ui->label_Image->width();
        ui->label_Image->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatioByExpanding));
        ui->label_Image->show();
    }

}


void NewPost::on_pushButton_sendPost_clicked()
{
    Post post(Username,ui->textEdit->toPlainText(),ImageAddress,false);
    ui->label_Image->hide();
    ImageAddress=nullptr;
    ui->textEdit->clear();
}

