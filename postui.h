#ifndef POSTUI_H
#define POSTUI_H

#include "post.h"
#include <QWidget>

namespace Ui {
class PostUi;
}

class PostUi : public QWidget, public Post
{
    Q_OBJECT

public:
    //Post ,/
    explicit PostUi(QString, unsigned int ,QWidget *parent = nullptr);
    ~PostUi();
    void HideSeeMoreBut();
    void AddCommentCounter();

private:
    Ui::PostUi *ui;
    //const QString TableName;
};

#endif // POSTUI_H
