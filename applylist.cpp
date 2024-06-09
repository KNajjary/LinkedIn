#include "applylist.h"
#include "applyview.h"
#include "mydatabase.h"
#include "ui_applylist.h"

ApplyList::ApplyList(QString username,unsigned int n,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ApplyList)
{
    ui->setupUi(this);
    Table=username+"_Job_"+QString::number(n)+"_Applys";
    MyDatabase db;

    int i=db.GetNumberOfRows(Table);
    //qDebug()<<i;
    //ui->toolBox_Applys->removeItem(0);
    for(;i>0;i--){
        ApplyView * ap=new ApplyView(Table,i);
        ap->show();
        ui->toolBox_Applys->addItem(ap,"Person"+QString::number(i));

    }

}

ApplyList::~ApplyList()
{
    delete ui;
}
