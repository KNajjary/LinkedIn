#include "post.h"
#include "like.h"
#include "mydatabase.h"

Post::Post(QString user,QString t, QString p,bool isRe /*,unsigned int n,unsigned int l,unsigned int r*/)
{
    SetText(t);
    SetPicture(p);
    SetTimeSent();
    SetSenderUsername(user);
    CommentCounter=0;
    LikeCounter=0;
    RepostCounter=0;
    ShareCounter=0;
    SetTableName(user + "_Posts");
    IsARepost=isRe;
    //
    MyDatabase db;
    SetNumber(db.GetNumberOfRows(GetTableName())+1);
    CommentTable=user+ "_Post"+ QString::number(GetNumber())+ "_Comments";
    LikeTable=user+ "_Post"+ QString::number(GetNumber())+ "_Likes";

    //create table

    db.CreatePostsTable(GetTableName());
    db.CreateCommentTable(CommentTable);
    db.CreateLikeTable(LikeTable);
    db.InsertPost(GetTableName(),GetText(),GetPicture(),GetTimeSent(),IsARepost);



}
unsigned int Post::AddRepostCounter(QString u)
{
    RepostCounter++;
    MyDatabase db;
    db.Update(GetTableName(),"RowNumber",GetNumber(),"RepostCounter",RepostCounter);
    Post rp(u,GetText(),GetPicture(),true);
    return RepostCounter;
}
unsigned int Post::AddLikeCounter(QString u)
{
    //qDebug()<<LikeCounter;
    LikeCounter++;
    //qDebug()<<LikeCounter;
    MyDatabase db;
    //qDebug()<<GetNumber()<<GetTableName();
    db.Update(GetTableName(),"RowNumber",GetNumber(),"LikeCounter",LikeCounter);
    Like l(GetLikeTable(),u);
    return LikeCounter;
}

unsigned int Post::AddCommentCounter()
{
    CommentCounter++;
    MyDatabase db;
    db.Update(GetTableName(),"RowNumber",GetNumber(),"CommentCounter",CommentCounter);
    return CommentCounter;
}
Post::Post(QString u,unsigned int n)
{
    SetNumber(n);
    SetSenderUsername(u);
    SetTableName(u+"_Posts");

    CommentTable=GetSenderUsername()+ "_Post"+ QString::number(GetNumber())+ "_Comments";
    LikeTable=GetSenderUsername()+ "_Post"+ QString::number(GetNumber())+ "_Likes";
    MyDatabase db;
    SetTimeSent(QDateTime::fromString(db.SelectWhere(GetTableName(),"RowNumber",n,"TimeSent",1)));
    SetText(db.SelectWhere(GetTableName(),"RowNumber",n,"Text",1));
    SetPicture(db.SelectWhere(GetTableName(),"RowNumber",n,"Picture",1));
    CommentCounter=db.SelectWhere(GetTableName(),"RowNumber",n,"CommentCounter",1).toInt();
    LikeCounter=db.SelectWhere(GetTableName(),"RowNumber",n,"LikeCounter",1).toInt();
    RepostCounter=db.SelectWhere(GetTableName(),"RowNumber",n,"RepostCounter",1).toInt();
    ShareCounter=db.SelectWhere(GetTableName(),"RowNumber",n,"ShareCounter",1).toInt();
    if(db.SelectWhere(GetTableName(),"RowNumber",n,"IsARepost",1).toInt() == 0)
        IsARepost=false;
    else IsARepost=true;
    if(db.SelectWhere("Users","Username",GetSenderUsername(),"IsCompany",1).toInt()==0)IsSenderACompany=false;
    else IsSenderACompany=true;
}
Post::Post(const Post & p)
{
    SetNumber(p.GetNumber());
    SetSenderUsername(p.GetSenderUsername());
    SetTableName(p.GetTableName());
    CommentTable=p.CommentTable;
    LikeTable = p.LikeTable;
    SetText(p.GetText());
    SetPicture(p.GetPicture());
    SetTimeSent(QDateTime::fromString(p.GetTimeSent()));
    CommentCounter=p.CommentCounter;
    LikeCounter=p.LikeCounter;
    RepostCounter= p.RepostCounter;
    ShareCounter= p.ShareCounter;
    IsARepost=p.IsARepost;


    IsSenderACompany=p.IsSenderACompany;
}
unsigned int Post::GetRepostCounter()
{
    return RepostCounter;
}
unsigned int Post::GetLikeCounter()
{
    return LikeCounter;
}
unsigned int Post::GetCommentCounter()
{
    return CommentCounter;
}
unsigned int Post::GetShareCounter()
{
    return ShareCounter;
}
QString Post::GetCommentTable()
{
    return CommentTable;
}
QString Post::GetLikeTable()
{
    return LikeTable;
}
bool Post::GetIsARepost()
{
    return IsARepost;
}
bool Post::HasLiked(QString u){
    MyDatabase db;
    return db.DoesExist(LikeTable,"Username",u);

}
bool Post::GetIsSenderACompany(){
    return IsSenderACompany;
}
bool Post::IsACompany(QString u)
{
    MyDatabase db;
    if(db.SelectWhere("Users","Username",u,"IsCompany",1).toInt()==0)return false;
    return true;
}
