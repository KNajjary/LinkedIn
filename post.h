#ifndef POST_H
#define POST_H

#include "content.h"
class Post :public Content
{
    QString CommentTable,LikeTable;
    unsigned int RepostCounter,LikeCounter,CommentCounter,ShareCounter;
public:
    Post(QString, QString , QString ,unsigned int /*=0, unsigned int =0,unsigned int =0*/);
    Post(QString, unsigned int);
    void AddRepostCounter();
    void AddLikeCounter();
    void AddCommentCounter();
    unsigned int GetRepostCounter();
    unsigned int GetLikeCounter();
    unsigned int GetCommentCounter();
    unsigned int GetShareCounter();
    QString GetCommentTable();
    QString GetLikeTable();

};

#endif // POST_H
