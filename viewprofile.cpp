#include "viewprofile.h"
#include "company.h"
#include "mydatabase.h"
#include "person.h"
#include "postui.h"
#include "ui_viewprofile.h"
#include <ostream>

ViewProfile::ViewProfile(QString u,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewProfile)
{
    ui->setupUi(this);
    Username=u;
    MyDatabase db;
    IsCompany = db.SelectWhere("Users","Username",u,"IsCompany",1).toInt();
    if(IsCompany)
        member= new Company(Username);
    else
        member = new Person(Username);

    SetLabels();
    ShowPosts();


}

ViewProfile::~ViewProfile()
{
    delete ui;
}
void ViewProfile::SetLabels()
{
    QPixmap Im(member->GetPicture());
    int LabelW,LabelH;
    LabelH=ui->label_Picture->height();
    LabelW=ui->label_Picture->width();
    ui->label_Picture->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatioByExpanding));
    //----------
    ui->label_Email->setText(member->GetEmail());
    ui->label_Phone->setText(member->GetPhone());

    if(IsCompany){

        ui->label_Name->setText(static_cast <Company *>(member)->GetCompanyName());
        ui->textBrowser_Skills->hide();
    }
    else{
        ui->label_Name->setText(static_cast <Person *> (member)->GetFirstName() + " " + static_cast <Person *> (member)->GetLastName());
        ui->textBrowser_Skills->setPlainText(static_cast <Person *> (member)->GetSkills());
    }


}
void ViewProfile::ShowPosts()
{
    //qDebug()<<ui->stackedWidget_Posts->count();
    unsigned int i = member->GetPostsCount();
    MyDatabase db;
    for(;i>0;i--)
    {
        PostUi * post=new PostUi(member->GetPostsTable(),i,ui->stackedWidget_Posts);
        post->HideSeeMoreBut();
        post->show();
        qDebug()<< ui->stackedWidget_Posts->addWidget(post);

        //box_Posts

    }
    //qDebug()<<ui->stackedWidget_Posts->count();


    /*//QGroupBox * box_Posts= new QGroupBox();
    QVBoxLayout * layout =new QVBoxLayout(); //qobject_cast <QVBoxLayout *> (box_Posts->layout()) ;

    //QWidget * widget_Posts = new QWidget();
    //widget_Posts.
    unsigned int i = member->GetPostsCount();
    //qDebug()<<i;
    MyDatabase db;
    for(;i>0;i--)
    {
        PostUi * post=new PostUi(member->GetPostsTable(),i,(QWidget *)layout);
        layout->addWidget(post);
        //box_Posts

    }
    //new QVBoxLayout();
    //box_Posts->setLayout(layout);

    ui->scrollArea_posts->setWidget((QWidget *)layout);*/
}

void ViewProfile::on_pushButton_nextPost_clicked()
{
    int i=ui->stackedWidget_Posts->currentIndex();
    i++;
    ui->stackedWidget_Posts->setCurrentIndex(i);

}


void ViewProfile::on_pushButton_prevPost_clicked()
{
    int i=ui->stackedWidget_Posts->currentIndex();
    i--;
    ui->stackedWidget_Posts->setCurrentIndex(i);
}

