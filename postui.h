#ifndef POSTUI_H
#define POSTUI_H

#include "member.h"
#include "person.h"
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
    explicit PostUi(QString, unsigned int ,QString,QWidget *parent = nullptr);
    ~PostUi();
    //PostUi(const PostUi & ,QString);
    //void HideSeeMoreBut();
    //void AddCommentCounter();
    //void ShowRepostedLabel();

private slots:
    void on_pushButton_Like_clicked();

    void on_pushButton_SeeMore_clicked();

    void on_pushButton_Repost_clicked();

    void on_pushButton_WhoLiked_clicked();

    void on_pushButton_Follow_clicked();

    void on_pushButton_Connect_clicked();
    void ShowSuggestedLabel();

private:
    Ui::PostUi *ui;
    const QString ViewerUsername;
    Member * Sender ;
    Person * Viewer;
    const unsigned int TextLimit=50;
    //friend class Home;
};

#endif // POSTUI_H
