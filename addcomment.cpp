#include "addcomment.h"
#include "ui_addcomment.h"
#include <QFileDialog>
#include "comment.h"
#include "postui.h"
AddComment::AddComment(QString su, unsigned int n,QString vu,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddComment)
    ,SenderUsername(su)
    , ViewerUsername(vu)
    , PostNumber(n)
{
    ui->setupUi(this);
    Post = new PostUi(SenderUsername,PostNumber,ViewerUsername);
    //Post->HideSeeMoreBut();
    //qDebug()<< Post->GetRepostCounter();
    Post->DisableCommentButton();
    Post->show();
    ui->verticalLayout->insertWidget(0,Post,Qt::AlignCenter);

    //
    ui->label_Image->hide();
    //
    if(Post->GetCommentCounter()==0)
    {
        ui->pushButton_Next->hide();
        ui->pushButton_Prev->hide();
    }
    else
    {
        ui->label_NoComment->hide();
    }
    //

    unsigned int i;
    for(i=1;i <= Post->GetCommentCounter();i++){
        //qDebug()<<i;
        Comment * co=new Comment(Post->GetCommentTable(),i);

        ui->stackedWidget_Comments->addWidget(co);
        co->show();
    }
}

AddComment::~AddComment()
{
    delete ui;
}

void AddComment::on_pushButton_send_clicked()
{
    Comment * co=new Comment(Post->GetCommentTable(),SenderUsername, ViewerUsername ,ui->textEdit_Text->toPlainText(),ImageAddress);
    //ui->scrollArea_comments->setWidget(co);
    //ui->scrollArea_comments->addScrollBarWidget(co,Qt::AlignVCenter);
    co->show();
    ui->stackedWidget_Comments->addWidget(co);

    Post->AddCommentCounterAndLabel();


    //ui->scrollArea_comments->setWidget((QWidget *)ui->verticalLayout_comments);

    //ui->scrollArea_comments->setWidgetResizable(true);

    ui->textEdit_Text->clear();
    ui->label_Image->hide();

//
    ui->label_NoComment->hide();
    ui->pushButton_Next->show();
    ui->pushButton_Prev->show();


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
        ui->label_Image->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatioByExpanding));
        ui->label_Image->show();
    }
}


void AddComment::on_pushButton_Next_clicked()
{
    int i=ui->stackedWidget_Comments->currentIndex();
    //qDebug()<<i;
    i++;
    ui->stackedWidget_Comments->setCurrentIndex(i);
}


void AddComment::on_pushButton_Prev_clicked()
{
    int i=ui->stackedWidget_Comments->currentIndex();
    i--;
    ui->stackedWidget_Comments->setCurrentIndex(i);
}

