#include "postui.h"
#include "company.h"
#include "mydatabase.h"
#include "person.h"
#include "qsqlerror.h"
#include "ui_postui.h"
#include <QSqlTableModel>
#include <QTableView>
//#include <iostream>
PostUi::PostUi(QString t, unsigned int n,QString u, QWidget *parent)
    : QWidget(parent)
    , Post(t,n) ,ui(new Ui::PostUi), ViewerUsername(u)
{
    ui->setupUi(this);
    //
    ui->label_suggested->hide();
    //
    if(!GetIsARepost())ui->label_reposted->hide();
    //
    if(GetText().isEmpty())
    {
        ui->pushButton_SeeMore->hide();
        ui->textBrowser_Text->hide();
    }

    else
    {
        QString s(GetText());
        if(s.size() > TextLimit){
          s.resize(TextLimit);
        }


        ui->textBrowser_Text->setText(s);
    }
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
        ui->label_Picture->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatioByExpanding));
    }
    //
    if(HasLiked(ViewerUsername))ui->pushButton_Like->setDisabled(true);
    //
    ui->label_CommentC->setText(QString::number(GetCommentCounter()));
    ui->label_LikeC->setText(QString::number(GetLikeCounter()));
    ui->label_RepostC->setText(QString::number(GetRepostCounter()));
    ui->label_ShareC->setText(QString::number(GetShareCounter()));
    //
    if(GetIsSenderACompany())ui->pushButton_Connect->hide();
    else ui->pushButton_Follow->hide();
    //
    if(IsACompany(ViewerUsername))
    {
        //ui->pushButton_Follow->setDisabled(true);
        //ui->pushButton_Connect->setDisabled(true);
        ui->pushButton_Follow->hide();
        ui->pushButton_Connect->hide();
        Sender= nullptr;
        Viewer= nullptr;
    }
    else if(GetIsSenderACompany())
    {
        Sender = new Company(GetSenderUsername());
        Viewer = new Person(ViewerUsername);
        if(Viewer->IsFollowing(GetSenderUsername())){
            ui->pushButton_Follow->setDisabled(true);
        }
    }
    else
    {
        Sender = new Person(GetSenderUsername());

        Viewer = new Person(ViewerUsername);
        if(static_cast<Person *>(Sender)->HasRequestedConnection(ViewerUsername)){
            ui->pushButton_Connect->setDisabled(true);
        }

    }

}
/*PostUi::PostUi(const PostUi & p,QString v)
    :Post(p.GetText(),p.GetNumber()) ,
    ViewerUsername(v)
{
    SetTimeSent(QDateTime::fromString(p.GetTimeSent()));
}*/
PostUi::~PostUi()
{
    delete ui;
}
/*void PostUi::HideSeeMoreBut(){
    ui->pushButton_SeeMore->hide();
}*/
/*void PostUi::AddCommentCounter(){
    int ComC = ui->label_CommentC->text().toInt();
    ComC++;
    ui->label_CommentC->setText(QString::number(ComC));
}*/

void PostUi::on_pushButton_Like_clicked()
{
    ui->label_LikeC->setText(QString::number(AddLikeCounter( ViewerUsername)));
}


void PostUi::on_pushButton_SeeMore_clicked()
{
    ui->textBrowser_Text->setText(GetText());
}
/*void PostUi::ShowRepostedLabel()
{
    ui->label_reposted->show();
}*/

void PostUi::on_pushButton_Repost_clicked()
{
    ui->label_RepostC->setText(QString::number(AddRepostCounter(ViewerUsername)));

}


void PostUi::on_pushButton_WhoLiked_clicked()
{
    MyDatabase db;
    QSqlQuery qr;
    qr.prepare("SELECT Username , Time FROM "+GetLikeTable()+";");

    qDebug()<<qr.lastError().text();
    qr.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qr);
    QTableView * tableview=new QTableView();
    tableview->setModel(model);
    tableview->setWindowModality(Qt::ApplicationModal);
    //tableview->setFrameStyle(4);
    tableview->setStyleSheet("background-color: rgb(190, 242, 255);");
    tableview->show();

}


void PostUi::on_pushButton_Follow_clicked()
{
    Viewer->FollowCompany(GetSenderUsername());
    static_cast<Company *>(Sender)->AddFollower(ViewerUsername);
}


void PostUi::on_pushButton_Connect_clicked()
{
    Viewer->RequestConnection(GetSenderUsername());
}
void PostUi::ShowSuggestedLabel()
{
    ui->label_suggested->show();
}
