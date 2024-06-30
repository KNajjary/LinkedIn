#include "home.h"
#include "mydatabase.h"
#include "newpost.h"
#include "person.h"
#include "post.h"
#include "ui_home.h"

Home::Home(QString u, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
    PostsLimit=9;
    ViewerUsername = u;
    IsViewerACompany = IsACompany(ViewerUsername);
    qDebug()<<IsViewerACompany;
    if(! IsViewerACompany)
    {
        AddPosts();
        SortPosts();
        ShowPosts();
    }


}
Home::~Home()
{
    delete ui;
}

void Home::on_pushButton_StartPost_clicked()
{
    NewPost * newp = new NewPost(ViewerUsername);
    newp->setWindowModality(Qt::ApplicationModal);
    newp->show();
}
bool Home::IsACompany(QString u)
{
    MyDatabase db;
    if(db.SelectWhere("Users","Username",u,"IsCompany",1).toInt()==0)return false;
    return true;
}
void Home::AddPosts()
{
    Person viewer(ViewerUsername);
    QString UsersTable="Users";
    MyDatabase db;
    int ConnectionsNum = db.GetNumberOfRows(viewer.GetConnectionsTable()),
        ConnectingsNum = db.GetNumberOfRows(viewer.GetConnectingsTable()),
        FollowingsNum = db.GetNumberOfRows(viewer.GetFollowingsTable()),
        AllUsersNum = db.GetNumberOfRows(UsersTable);
    qDebug()<<"ConnectionsNum "<<ConnectionsNum
             <<"ConnectingsNum" <<ConnectingsNum
             <<"FollowingsNum "<< FollowingsNum
             << "AllUsersNum"<<AllUsersNum;
    //-------------------------------------------
    while(FollowingsNum > 0)
    {
        QString username = db.Select(viewer.GetFollowingsTable(),"Username",FollowingsNum);
        FolConUsernames.push_back(username);
        int PostCount= db.GetNumberOfRows(username+"_Posts");
        while(PostCount > 0){
            Post p(username,PostCount);
            Posts1.push_back(p);

            PostCount--;
        }
        FollowingsNum--;
    }
    qDebug()<<"1";
    //-------------------------------------------
    while(ConnectionsNum > 0)
    {
        QString username = db.Select(viewer.GetConnectionsTable(),"Username",ConnectionsNum);
        FolConUsernames.push_back(username);
        int PostCount= db.GetNumberOfRows(username+"_Posts");
        while(PostCount > 0){
            Post p(username,PostCount);
            Posts1.push_back(p);
            PostCount--;
        }
        ConnectionsNum--;
    }
    qDebug()<<"2";
    //-------------------------------------------

    while(ConnectingsNum > 0)
    {
        MyDatabase db;
        QString username = db.Select(viewer.GetConnectingsTable(),"Username",ConnectingsNum);
        FolConUsernames.push_back(username);
        int PostCount= db.GetNumberOfRows(username+"_Posts");
        while(PostCount > 0){
            Post p(username,PostCount);
            Posts1.push_back(p);
            PostCount--;
        }
        ConnectingsNum--;
    }
    qDebug()<<"3";
    //-------------------------------------------
    while(AllUsersNum > 0)
    {


        MyDatabase db;
        qDebug()<<AllUsersNum;
        QString username = db.Select(UsersTable ,"Username",AllUsersNum );
        if(username == ViewerUsername || DoesUsernameExist(username)){
            AllUsersNum--;
            continue;
        }

        int PostsCount= db.GetNumberOfRows(username+"_Posts");
        while(PostsCount > 0){
            Post p(username,PostsCount);
            if(db.Select(UsersTable ,"Career",AllUsersNum ) == viewer.GetCareer()){
                Posts2.push_back(p);
            }
            else{
                Posts3.push_back(p);
            }

            PostsCount--;
        }
        AllUsersNum--;
    }
    qDebug()<<"4";

}

bool Home::DoesUsernameExist(QString u){
    int i= FolConUsernames.size() -1;
    for(; i>=0 ; i--){
        if(FolConUsernames[i]==u)break;
    }
    if(i>=0)
        return true;
    else
        return false;
}
void Home::SortPosts()
{
    int i ,l =Posts1.size();
    bool changed = true;
    while(l>0 && changed)
    {
        changed = false;
        for(i=0 ; i<l-1 ; i++ )
        {
            if(QDateTime::fromString(Posts1[i].GetTimeSent()) > QDateTime::fromString(Posts1[i+1].GetTimeSent())){
                Post p(Posts1[i]);
                Posts1[i] = Posts1[i+1];
                Posts1[i+1] = p;
                changed =true;

            }
        }
        l--;
    }
    //------------------------------------------------------
    l =Posts2.size();
    changed = true;
    while(l>0 && changed)
    {
        changed = false;
        for(i=0 ; i<l-1 ; i++ )
        {
            if(QDateTime::fromString(Posts2[i].GetTimeSent()) > QDateTime::fromString(Posts2[i+1].GetTimeSent())){
                Post p(Posts2[i]);
                Posts2[i] = Posts2[i+1];
                Posts2[i+1] = p;
                changed =true;

            }
        }
        l--;
    }
    //------------------------------------------------------
    l =Posts3.size();
    changed = true;
    while(l>0 && changed)
    {
        changed = false;
        for(i=0 ; i<l-1 ; i++ )
        {
            if(QDateTime::fromString(Posts3[i].GetTimeSent()) > QDateTime::fromString(Posts3[i+1].GetTimeSent())){
                Post p(Posts3[i]);
                Posts3[i] = Posts3[i+1];
                Posts3[i+1] = p;
                changed =true;

            }
        }
        l--;
    }
    //------------------------------------------------------


}
void Home::ShowPosts()
{
    unsigned int i ;
    for(i=0; i<Posts1.size() ;i++){
        PostUi *p = new PostUi(Posts1[i].GetSenderUsername(),Posts1[i].GetNumber(),ViewerUsername);
        p->show();
        ui->stackedWidget_Potst->addWidget(p);

    }
    //------------------------------------------------------
    for(i=0; i<Posts2.size() ;i++){
        PostUi *p = new PostUi(Posts2[i].GetSenderUsername(),Posts2[i].GetNumber(),ViewerUsername);
        p->show();
        ui->stackedWidget_Potst->addWidget(p);

    }
    //------------------------------------------------------
    for(i=0; i<Posts3.size() ;i++){
        PostUi *p = new PostUi(Posts3[i].GetSenderUsername(),Posts3[i].GetNumber(),ViewerUsername);
        p->show();
        ui->stackedWidget_Potst->addWidget(p);

    }
    //------------------------------------------------------

}
void Home::on_pushButton_next_clicked()
{
    int i=ui->stackedWidget_Potst->currentIndex();
    if(i == PostsLimit)
        return;
    i++;
    ui->stackedWidget_Potst->setCurrentIndex(i);

}


void Home::on_pushButton_prev_clicked()
{
    int i=ui->stackedWidget_Potst->currentIndex();
    i--;
    ui->stackedWidget_Potst->setCurrentIndex(i);
}


void Home::on_pushButton_loadMoreP_clicked()
{
    int i=ui->stackedWidget_Potst->currentIndex();
    if(i == PostsLimit)PostsLimit+=10;
}

