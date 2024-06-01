#include "postui.h"
#include "ui_postui.h"

PostUi::PostUi(QString t, unsigned int n, QWidget *parent)
    : QWidget(parent)
    , Post(t,n) ,ui(new Ui::PostUi)
{
    ui->setupUi(this);
    //
    if(GetText().isEmpty())
        ui->textBrowser_Text->hide();
    else
        ui->textBrowser_Text->setText(GetText());
    //
    if(GetPicture().isEmpty())
    {
        ui->label_Picture->hide();
    }
    else
    {
        QPixmap Im(GetPicture());
        int LabelW,LabelH;
        LabelH=ui->label_Picture->height();
        LabelW=ui->label_Picture->width();
        ui->label_Picture->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatio));
    }

    //
    ui->label_CommentC->setText(QString::number(GetCommentCounter()));
    ui->label_LikeC->setText(QString::number(GetLikeCounter()));
    ui->label_RepostC->setText(QString::number(GetRepostCounter()));
    ui->label_ShareC->setText(QString::number(GetShareCounter()));

}

PostUi::~PostUi()
{
    delete ui;
}
void PostUi::HideSeeMoreBut(){
    ui->pushButton_SeeMore->hide();
}
void PostUi::AddCommentCounter(){
    int ComC = ui->label_CommentC->text().toInt();
    ComC++;
    ui->label_CommentC->setText(QString::number(ComC));
}
