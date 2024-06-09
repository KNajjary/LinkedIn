#include "jobui.h"
#include "mydatabase.h"
#include "ui_jobui.h"

JobUi::JobUi(QString username, unsigned int number, QString u,QWidget *parent)
    : QWidget(parent)
    , Job(username,number)
    ,ui(new Ui::JobUi)
{
    ui->setupUi(this);
    PersonUsername=u;
    //
    SetLabels();
    SetButton();


}
JobUi::JobUi(QString username, unsigned int number,QWidget *parent)
    : QWidget(parent)
    , Job(username,number)
    ,ui(new Ui::JobUi)
{
    ui->setupUi(this);
    PersonUsername=NULL;
    //
    SetLabels();
    SetButton();


}

JobUi::~JobUi()
{
    delete ui;
}
void JobUi::SetLabels()
{
    ui->label_Company->setText(GetCompany());
    ui->label_Name->setText(GetName());
    ui->label_Field->setText(GetField());
    ui->label_Location->setText(GetLocation());
    ui->label_TimeCreated->setText(GetTimeCreated());
    ui->label_salary->setText(GetSalary());
    ui->textBrowser_skils->setPlainText(GetSkillsRequired());
    ui->label_Time->setText(GetTime());
    ui->label_WorkplaceType->setText(GetWorkplaceType());

    if(!GetIsClosed())
        ui->label_closed->hide();
    else ui->pushButton_apply->setEnabled(false);

    QPixmap Im(GetProfile());
    int LabelW,LabelH;
    LabelH=ui->label_prifile->height();
    LabelW=ui->label_prifile->width();
    ui->label_prifile->setPixmap(Im.scaled(LabelW,LabelH,Qt::KeepAspectRatioByExpanding));

}
void JobUi::SetButton()
{
    if(PersonUsername.isNull()){
        ui->pushButton_apply->hide();
        return;
    }
    QString text=GetStatus(PersonUsername);

    if(! text.isEmpty()){
        ui->pushButton_apply->setText(text);
        ui->pushButton_apply->setEnabled(false);
    }
    else ui->pushButton_apply->setText("Apply");


}

void JobUi::on_pushButton_apply_clicked()
{
    MyDatabase db;
    db.InsertApply(GetAppliedTable(),PersonUsername,"Pending");
    SetButton();
}

