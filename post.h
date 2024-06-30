#ifndef POST_H
#define POST_H

#include "content.h"
class Post :public Content
{
    QString CommentTable,LikeTable;
    unsigned int RepostCounter,LikeCounter,CommentCounter,ShareCounter;
    bool IsARepost,IsSenderACompany;
public:
    Post(QString, QString , QString,bool /*,unsigned int =0, unsigned int =0,unsigned int =0*/);
    Post(QString, unsigned int);
    Post(const Post &);
    unsigned int AddRepostCounter(QString);
    unsigned int AddLikeCounter(QString);
    unsigned int AddCommentCounter();
    unsigned int GetRepostCounter();
    unsigned int GetLikeCounter();
    unsigned int GetCommentCounter();
    unsigned int GetShareCounter();
    QString GetCommentTable();
    QString GetLikeTable();
    bool GetIsARepost();
    bool GetIsSenderACompany();
    bool HasLiked(QString);
    bool IsACompany(QString);

    friend class Home;
};

#endif // POST_H
