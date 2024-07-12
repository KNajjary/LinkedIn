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
    explicit AddComment(QString,unsigned int , QString ,QWidget *parent = nullptr);
    ~AddComment();

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_chooseIm_clicked();

    void on_pushButton_Next_clicked();

    void on_pushButton_Prev_clicked();

private:
    Ui::AddComment *ui;
    QString ImageAddress;
    const QString SenderUsername, ViewerUsername;
    unsigned int PostNumber;//= RowNumber
    PostUi * Post;
    //PostUi Post;
};

#endif // ADDCOMMENT_H
