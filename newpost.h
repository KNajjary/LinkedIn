#ifndef NEWPOST_H
#define NEWPOST_H

#include <QWidget>

namespace Ui {
class NewPost;
}

class NewPost : public QWidget
{
    Q_OBJECT

public:
    explicit NewPost(QString,QWidget *parent = nullptr);
    ~NewPost();

private slots:
    void on_pushButton_selectImage_clicked();

    void on_pushButton_sendPost_clicked();

private:
    Ui::NewPost *ui;
    QString ImageAddress,Username;
};

#endif // NEWPOST_H
