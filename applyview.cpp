#include "applyview.h"
#include "mydatabase.h"
#include "ui_applyview.h"

ApplyView::ApplyView(QString table, unsigned int n, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ApplyView)
{
    ui->setupUi(this);
    ApplyTable=table;
    MyDatabase db;
    Username=db.Select(ApplyTable,"Username",n);
    QString state=db.SelectWhere(ApplyTable,"Username",Username,"Status",1);

    person = new Person(Username);
    ui->label_Name->setText(person->GetFirstName()+" "+person->GetLastName());
    QPixmap Im(person->GetPicture());
    unsigned int h = ui->label_Prof->height();
    unsigned int w=ui->label_Prof->width();
    ui->label_Prof->setPixmap(Im.scaled(w,h,Qt::KeepAspectRatioByExpanding));

    if(state != "Pending"){
        ui->label_Status->setText(state);
        //ui->label_Status
        ui->pushButton_Accept->setEnabled(false);
        ui->pushButton_Ignore->setEnabled(false);
    }
    else ui->label_Status->hide();
    //qDebug()<<state;

}

ApplyView::~ApplyView()
{
    delete ui;
}


void ApplyView::on_pushButton_Accept_clicked()
{
    MyDatabase db;
    db.Update(ApplyTable,"Username",Username,"Status",QString::fromStdString("Accepted"));

    ui->label_Status->setText("Accepted");
    ui->label_Status->show();
    ui->pushButton_Accept->setEnabled(false);
    ui->pushButton_Ignore->setEnabled(false);
}


void ApplyView::on_pushButton_Ignore_clicked()
{
    MyDatabase db;
    db.Update(ApplyTable,"Username",Username,"Status",QString::fromStdString("Ignored"));

    ui->label_Status->setText("Ignored");
    ui->label_Status->show();
    ui->pushButton_Accept->setEnabled(false);
    ui->pushButton_Ignore->setEnabled(false);
}

