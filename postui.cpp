#include "postui.h"
#include "ui_postui.h"

PostUi::PostUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PostUi)
{
    ui->setupUi(this);
}

PostUi::~PostUi()
{
    delete ui;
}
