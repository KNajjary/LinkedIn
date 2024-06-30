#ifndef VIEWPROFILE_H
#define VIEWPROFILE_H

#include "member.h"
#include <QMainWindow>

namespace Ui {
class ViewProfile;
}

class ViewProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewProfile(QString ,QString , QWidget *parent = nullptr);
    ~ViewProfile();

private slots:
    void on_pushButton_nextPost_clicked();

    void on_pushButton_prevPost_clicked();

private:
    Ui::ViewProfile *ui;
    QString Username,MyUsername;
    Member * member;
    bool IsCompany;
    void SetLabels();
    void ShowPosts();
};

#endif // VIEWPROFILE_H
