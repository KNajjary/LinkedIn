#include "addcomment.h"
#include "ui_addcomment.h"
#include <QFileDialog>
#include "comment.h"
#include "postui.h"
AddComment::AddComment(QString t,QString u,unsigned int n,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddComment) ,TableName(t) , Username(u), PostNumber(n)
{
    ui->setupUi(this);
    Post = new PostUi(TableName,PostNumber,Username);
    //Post->HideSeeMoreBut();
    ui->verticalLayout_Post->addWidget(Post);
    ui->label_Image->hide();
}

AddComment::~AddComment()
{
    delete ui;
}

void AddComment::on_pushButton_send_clicked()
{
    Comment * co=new Comment(Post->GetCommentTable(), Username,ui->textEdit_Text->toPlainText(),ImageAddress);
    //ui->scrollArea_comments->setWidget(co);
    //ui->scrollArea_comments->addScrollBarWidget(co,Qt::AlignVCenter);
    ui->verticalLayout_comments->addWidget(co);
    ui->scrollArea_comments->setWidget((QWidget *)ui->verticalLayout_comments);

    ui->scrollArea_comments->setWidgetResizable(true);

    ui->textEdit_Text->clear();
    ui->label_Image->hide();
    Post->AddCommentCounter();




}


void AddComment::on_pushButton_chooseIm_clicked()
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
        ui->label_Image->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatio));
        ui->label_Image->show();
    }
}

