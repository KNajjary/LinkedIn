#include "post.h"
#include "mydatabase.h"

Post::Post(QString user,QString t, QString p ,unsigned int n/*,unsigned int l,unsigned int r*/)
{
    SetText(t);
    SetPicture(p);
    SetTimeSent();
    CommentCounter=0;
    LikeCounter=0;
    RepostCounter=0;
    ShareCounter=0;
    SetTableName(user + "_" + "Posts");
    CommentTable=user+ "_Post"+ QString::number(n)+ "_Comments";
    LikeTable=user+ "_Post"+ QString::number(n)+ "_Likes";
    //create table
    MyDatabase db;
    db.CreatePostsTable(GetTableName());
    db.CreateCommentTable(CommentTable);
    db.CreateLikeTable(LikeTable);
    db.InsertPost(GetTableName(),GetText(),GetPicture(),GetTimeSent());


}
void Post::AddRepostCounter()
{
    RepostCounter++;
}
void Post::AddLikeCounter()
{
    LikeCounter++;
}

void Post::AddCommentCounter()
{
    CommentCounter++;
}
Post::Post(QString t ,unsigned int n)
{
    MyDatabase db;
    SetText(db.SelectWhere(t,"RowNumber",n,"Text",1));
    SetPicture(db.SelectWhere(t,"RowNumber",n,"Picture",1));
    CommentCounter=db.SelectWhere(t,"RowNumber",n,"CommentCounter",1).toInt();
    LikeCounter=db.SelectWhere(t,"RowNumber",n,"LikeCounter",1).toInt();
    RepostCounter=db.SelectWhere(t,"RowNumber",n,"RepostCounter",1).toInt();
    ShareCounter=db.SelectWhere(t,"RowNumber",n,"ShareCounter",1).toInt();

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
