#include "newjob.h"
#include "job.h"
#include "mydatabase.h"
#include "ui_newjob.h"

NewJob::NewJob(QString u, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NewJob)
{
    ui->setupUi(this);
    ui->label_allReq->hide();
    Username=u;
    MyDatabase db;
    QString Company = db.SelectWhere("Users","Username",Username,"CompanyName",1);
    ui->lineEdit_Company->setText( Company);

}

NewJob::~NewJob()
{
    delete ui;
}

void NewJob::on_pushButton_Create_clicked()
{
    ui->label_allReq->hide();
    if(ui->lineEdit_Name->text().isEmpty() ||
        ui->lineEdit_Company->text().isEmpty() ||
        ui->lineEdit_Location->text().isEmpty() ||
        ui->lineEdit_Salary->text().isEmpty() ||
        ui->textEdit_Skills->toPlainText().isEmpty()
        ){
        ui->label_allReq->show();
        return;
    }
    Job j(Username,
          ui->lineEdit_Name->text(),
          ui->lineEdit_Company->text(),
          ui->comboBox_workplace->currentText(),
          ui->lineEdit_Location->text(),
          ui->comboBox_Time->currentText(),
          ui->textEdit_Skills->toPlainText(),
          ui->lineEdit_Salary->text(),
          ui->comboBox_Field->currentText());

    this->close();
}

