#ifndef ADDCOMMENT_H
#define ADDCOMMENT_H

#include "postui.h"
#include <QWidget>

namespace Ui {
class AddComment;
}

class AddComment : public QWidget
{
    Q_OBJECT

public:
    explicit AddComment(QString , QString,unsigned int ,QWidget *parent = nullptr);
    ~AddComment();

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_chooseIm_clicked();

private:
    Ui::AddComment *ui;
    QString ImageAddress;
    const QString TableName, Username;
    unsigned int PostNumber;//= RowNumber
    PostUi * Post;
    //PostUi Post;
};

#endif // ADDCOMMENT_H
