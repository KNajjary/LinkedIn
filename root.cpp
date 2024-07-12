#include "root.h"
#include "home.h"
#include "mydatabase.h"
#include "profileicon.h"
#include "qlabel.h"
//#include "qlistview.h"
#include "qtoolbox.h"
#include "ui_root.h"
enum PageNumber{
    home =0,
    myNetwork,
    jobs,
    //messaging,
    me
};

Root::Root(QString u,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Root)
{
    ui->setupUi(this);
    ViewerUsername = u;
    MyDatabase db;
    if(db.SelectWhere("Users","Username",u,"IsCompany",1).toInt()==0)
        IsViewerACompany = false;
    else
        IsViewerACompany = true;
    //-----------------
    HomeP = new Home(ViewerUsername);
    MeP = new Me(ViewerUsername) ;
    //HomeP->show();
    //MeP->show();
    ui->stackedWidget_Pages->insertWidget(home ,HomeP);
    //-------------
    if(IsViewerACompany)
    {
        MyNetwork_CompanyP = new MyNetwork_Company(ViewerUsername);
        MyNetwork_PersonP = nullptr;
        ViewJobs_CompanyP = new ViewJobs_Company(ViewerUsername);
        ViewJobs_PersonP = nullptr;
        //
        //MyNetwork_CompanyP->show();
        //ViewJobs_CompanyP->show();
        //
        ui->stackedWidget_Pages->insertWidget(myNetwork , MyNetwork_CompanyP);
        ui->stackedWidget_Pages->insertWidget(jobs , ViewJobs_CompanyP);
    }
    else
    {
        MyNetwork_CompanyP = nullptr;
        MyNetwork_PersonP = new MyNetwork_Person(ViewerUsername);
        ViewJobs_CompanyP = nullptr;
        ViewJobs_PersonP = new ViewJobs_Person(ViewerUsername);
        //
        //MyNetwork_PersonP->show();
        //ViewJobs_PersonP->show();
        //
        ui->stackedWidget_Pages->insertWidget(myNetwork , MyNetwork_PersonP);
        ui->stackedWidget_Pages->insertWidget(jobs , ViewJobs_PersonP);

    }
    ui->stackedWidget_Pages->insertWidget(me , MeP);
   //
    QLabel * label_Backg= new QLabel(this);
    label_Backg->setGeometry(this->geometry());
    QPixmap Im("D://Linked In//RootBackground.png");
    int LabelW,LabelH;
    LabelH=label_Backg->height();
    LabelW=label_Backg->width();
    label_Backg->setPixmap(Im.scaled(LabelW,LabelH,Qt::IgnoreAspectRatio/*ByExpanding*/));
    label_Backg->lower();
    //
    ui->stackedWidget_Pages->setCurrentIndex(home);
    //
    ui->label->setGeometry(ui->stackedWidget_Pages->geometry());
}

Root::~Root()
{
    delete ui;
}

void Root::on_pushButton_Home_clicked()
{
    SetAllButtonsUnclicked();
    ui->pushButton_Home->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(54,111,235);"
        "font: 15pt  Segoe UI;"
        "}"
        );
    ui->stackedWidget_Pages->setCurrentIndex(home);
}


void Root::on_pushButton_MyNetw_clicked()
{
    SetAllButtonsUnclicked();
    ui->pushButton_MyNetw->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(54,111,235);"
        "font: 15pt  Segoe UI;"
        "}"
        );
    ui->stackedWidget_Pages->setCurrentIndex(myNetwork);

}


void Root::on_pushButton_Jobs_clicked()
{
    SetAllButtonsUnclicked();
    ui->pushButton_Jobs->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(54,111,235);"
        "font: 15pt  Segoe UI;"
        "}"
        );
    ui->stackedWidget_Pages->setCurrentIndex(jobs);

}


void Root::on_pushButton_Messaging_clicked()
{
    SetAllButtonsUnclicked();
    //ui->stackedWidget_Pages->setCurrentIndex(messaging);
    ui->pushButton_Messaging->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(54,111,235);"
        "font: 15pt  Segoe UI;"
        "}"
        );
}


void Root::on_pushButton_Me_clicked()
{
    SetAllButtonsUnclicked();
    ui->pushButton_Me->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(54,111,235);"
        "font: 15pt  Segoe UI;"
        "}"
        );
    ui->stackedWidget_Pages->setCurrentIndex(me);

}
void Root::SetAllButtonsUnclicked(){
    ui->pushButton_Home->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(20,176,191);"
        "font: 15pt  Segoe UI;"
        "}"
    );
    ui->pushButton_Me->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(20,176,191);"
        "font: 15pt  Segoe UI;"
        "}"
    );
    ui->pushButton_Messaging->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(20,176,191);"
        "font: 15pt  Segoe UI;"
        "}"
    );
    ui->pushButton_MyNetw->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(20,176,191);"
        "font: 15pt  Segoe UI;"
        "}"
    );
    ui->pushButton_Jobs->setStyleSheet(
        "QPushButton {"
        "background-color: rgb(20,176,191);"
        "font: 15pt  Segoe UI;"
        "}"
    );
}


void Root::on_pushButton_Reload_clicked()
{
    switch(ui->stackedWidget_Pages->currentIndex())
    {
        case (home):{
            ui->stackedWidget_Pages->removeWidget(HomeP);
            HomeP = new Home(ViewerUsername);
            ui->stackedWidget_Pages->insertWidget(home ,HomeP);
            ui->stackedWidget_Pages->setCurrentIndex(home);
            break;
        }
        case (me):{
            ui->stackedWidget_Pages->removeWidget(MeP);
            MeP = new Me(ViewerUsername) ;
            ui->stackedWidget_Pages->insertWidget(me , MeP);
            ui->stackedWidget_Pages->setCurrentIndex(me);
            break;

        }
        case (jobs):{
            if(IsViewerACompany)
            {
                ui->stackedWidget_Pages->removeWidget(ViewJobs_CompanyP);
                ViewJobs_CompanyP = new ViewJobs_Company(ViewerUsername);
                ui->stackedWidget_Pages->insertWidget(jobs , ViewJobs_CompanyP);
            }
            else
            {
                ui->stackedWidget_Pages->removeWidget(ViewJobs_PersonP);
                ViewJobs_PersonP = new ViewJobs_Person(ViewerUsername);
                ui->stackedWidget_Pages->insertWidget(jobs , ViewJobs_PersonP);

            }
            ui->stackedWidget_Pages->setCurrentIndex(jobs);
            break;
        }
        case(myNetwork):{
            if(IsViewerACompany)
            {
                ui->stackedWidget_Pages->removeWidget(MyNetwork_CompanyP);
                MyNetwork_CompanyP = new MyNetwork_Company(ViewerUsername);
                ui->stackedWidget_Pages->insertWidget(myNetwork , MyNetwork_CompanyP);


            }
            else
            {
                ui->stackedWidget_Pages->removeWidget(MyNetwork_PersonP);
                MyNetwork_PersonP = new MyNetwork_Person(ViewerUsername);
                ui->stackedWidget_Pages->insertWidget(myNetwork , MyNetwork_PersonP);

            }
            ui->stackedWidget_Pages->setCurrentIndex(myNetwork);
            break;
        }
    }
}


void Root::on_pushButton_Search_clicked()
{
    QString SearchedUsername= ui->lineEdit_SearchUsername->text(),
        Table="Users";
    MyDatabase db;
    unsigned int i;
    QToolBox * ToolBox = new QToolBox();
    for(i=1; i<=db.GetNumberOfRows(Table) ;i++)
    {
        //MyDatabase db;
        if(db.Select(Table,"Username",i).contains(SearchedUsername,Qt::CaseInsensitive))
        {
            //MyDatabase db;

            ProfileIcon * p= new ProfileIcon(ViewerUsername , db.Select(Table,"Username",i));
            ToolBox->addItem(p , db.Select(Table,"Username",i));
            //qDebug() << i<<db.Select(Table,"Username",i);


        }
    }
    ToolBox->show();
}

