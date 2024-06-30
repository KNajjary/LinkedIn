#ifndef HOME_H
#define HOME_H

#include "post.h"
#include "postui.h"
#include <QWidget>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QString , QWidget *parent = nullptr);
    ~Home();

private slots:
    void on_pushButton_StartPost_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_prev_clicked();

    void on_pushButton_loadMoreP_clicked();

private:
    Ui::Home *ui;
    QString ViewerUsername;
    bool IsACompany(QString);
    bool IsViewerACompany;
    void AddPosts();
    //void ShowSameCareerPosts();
    //void ShowRemainedPosts();
    bool DoesUsernameExist(QString);
    std::vector <Post> Posts1,Posts2,Posts3;
    std::vector <QString> FolConUsernames;
    void SortPosts();
    void ShowPosts();
    int PostsLimit;
};

#endif // HOME_H
