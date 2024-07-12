#include "completeuserinfowindow.h"
#include "completecompanyinfo.h"
#include "mydatabase.h"
#include "root.h"
#include "ui_completeuserinfowindow.h"

#include <QDebug>
#include <QMessageBox>
//#include <new>
#include "user.h"
//#include "verificationwindow.h"
#include "LogAndSignInWindow.h"
CompleteUserInfoWindow::CompleteUserInfoWindow(QString u,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CompleteUserInfoWindow)
{
    ui->setupUi(this);
    //user = NULL;
    Username=u;
    ui->label_EmployTypeNotValid->hide();
    ui->InValidFirstNam->hide();
    ui->InvalidLastNam->hide();
    ui->label_MajorNotValid->hide();
    ui->InvalidEmail->hide();
    ui->InvalidPhone->hide();


    QPixmap Im1("D://Linked In//CompleteUserInfoWindowIm1.png");
    int Label1W,Label1H;
    Label1H=ui->Imlabel_1->height();
    Label1W=ui->Imlabel_1->width();
    ui->Imlabel_1->setPixmap(Im1.scaled(Label1W,Label1H,Qt::KeepAspectRatio));

    QPixmap Im2("D://Linked In//CompleteUserInfoWindowIm2.png");
    int Label2W,Label2H;
    Label2H=ui->Imlabel_2->height();
    Label2W=ui->Imlabel_2->width();
    ui->Imlabel_2->setPixmap(Im2.scaled(Label2W,Label2H,Qt::KeepAspectRatio));

    QPixmap Im3("D://Linked In//CompleteUserInfoWindowIm3.png");
    int Label3W,Label3H;
    Label3H=ui->Imlabel_3->height();
    Label3W=ui->Imlabel_3->width();
    ui->Imlabel_3->setPixmap(Im3.scaled(Label3W,Label3H,Qt::KeepAspectRatio));
}

CompleteUserInfoWindow::~CompleteUserInfoWindow()
{
    delete ui;
}
/*void CompleteUserInfoWindow::SetUser(User * u){
    User = u;
    //return;
}
*/
void CompleteUserInfoWindow::on_pushButton_Done_clicked()
{

    ui->label_EmployTypeNotValid->hide();
    ui->InValidFirstNam->hide();
    ui->InvalidLastNam->hide();
    ui->label_MajorNotValid->hide();
    ui->InvalidEmail->hide();
    ui->InvalidPhone->hide();



    bool invalidity= false;
    qDebug() << "Enter on_pushButton_Done_clicked";
    User User(Username ,LogAndSignInWindow:: Password);
    qDebug()<< Username << LogAndSignInWindow::Password;
    if(! ui->lineEdit_FirstName->text().isEmpty())
    {
        if(! User.SetFirstName(ui->lineEdit_FirstName->text())){
            ui->InValidFirstNam->show();
            invalidity = true;
        }

    }
            //QMessageBox::critical(this," Error inserting data in database","Inserting  your first name in database is unsseccesful 😔");
            //qDebug()<< " Error inserting data in database";
    if(! ui->lineEdit_LastName->text().isEmpty())
    {
        if(! User.SetLastName(ui->lineEdit_LastName->text())){

            ui->InvalidLastNam->show();
            invalidity = true;
        }
    }

    if(! ui->lineEdit_Email->text().isEmpty())
    {
        if(! User.SetEmail(ui->lineEdit_Email->text())){

            ui->InvalidEmail->show();
            invalidity = true;
        }
    }
    if(! ui->lineEdit_PhoneNumber->text().isEmpty())
    {
        if(! User.SetPhone(ui->lineEdit_PhoneNumber->text())){

            ui->InvalidPhone->show();
            invalidity = true;
        }
    }
    if(! ui->lineEdit_EducationInfoMajor->text().isEmpty()){
        if(! User.SetEducationInfoMajor( ui->lineEdit_EducationInfoMajor->text() )){
            ui->label_MajorNotValid->show();
            invalidity = true;
        }
    }
    if(! ui->lineEdit_PrevEmploymentsEmploymentTipe->text().isEmpty()){
        if(! User.SetPrevEmploymentEmploymentTipe(ui->lineEdit_PrevEmploymentsEmploymentTipe->text())){
            ui->label_EmployTypeNotValid->show();
            invalidity = true;
        }
    }
    if(! ui->lineEdit_PrevEmploymentsCompanyName->text().isEmpty())
        User.SetPrevEmploymentCompanyName( ui->lineEdit_PrevEmploymentsCompanyName->text() );
    if(! ui->lineEdit_PrevEmploymentsCompanyName->text().isEmpty())
        User.SetPrevEmploymentCompanyName(ui->lineEdit_PrevEmploymentsCompanyName->text());

    if(! ui->lineEdit_EducationInfoGrade->text().isEmpty())
        User.SetEducationInfoGrade( ui->lineEdit_EducationInfoGrade->text() );
    if(! ui->lineEdit_EducationInfoSchoolName->text().isEmpty())
        User.SetEducationInfoSchoolName( ui->lineEdit_EducationInfoSchoolName->text() );
    User.SetAddressCountry(ui->comboBox_Country->currentText());
    User.SetAddressProvince(ui->comboBox_Province->currentText());
    User.SetAddressCity(ui->comboBox_City->currentText());
    User.SetBirthDateYear(ui->dateEdit_Birthdate->date().year());
    User.SetBirthDateMonth(ui->dateEdit_Birthdate->date().month());
    User.SetBirthDateDay(ui->dateEdit_Birthdate->date().day());
    User.SetEducationInfoEndYear( ui->spinBox_EducationInfoEndYear->value());
    User.SetEducationInfoEndYear( ui->spinBox_EducationInfoStartYear->value());
    User.SetPrevEmploymentStartYear(ui->spinBox_PrevEmploymentsStartYear->value());
    User.SetPrevEmploymentEndYear(ui->spinBox_PrevEmploymentsEndYear->value());

    if(ui->radioButton_Over18->isChecked())
        User.SetOver18(true);
    else
        User.SetOver18(false);

    if(ui->radioButton_IGraduated->isChecked())
        User.SetEducationInfoFinished(true);
    else
        User.SetEducationInfoFinished(false);

    MyDatabase db;
    db.Update("Users","Username", Username ,"IsCompany", false );
    db.Update("Users","Username", Username ,"Skills", ui->textBrowser_Skills->toPlainText());







    if(! invalidity){
        Root * root = new Root(Username);
        root->show();
        this->close();
        ui->~CompleteUserInfoWindow();
    }

}
/*
 * const User*  CompleteUserInfoWindow::GetUser(){
    return this->User;
}
*/




/*void CompleteUserInfoWindow::on_pushButton_AdEdu_clicked()
{

}


void CompleteUserInfoWindow::on_pushButton_AddPo_clicked()
{

}*/





void CompleteUserInfoWindow::on_pushButton_AreYouCompany_clicked()
{
    CompleteCompanyInfo * c =new CompleteCompanyInfo(LogAndSignInWindow::Username);
    c->show();
    this->close();
    ui->~CompleteUserInfoWindow();
}
void CompleteUserInfoWindow::Hide_pushButton_AreYouCompany(){
    ui->pushButton_AreYouCompany->hide();
}
