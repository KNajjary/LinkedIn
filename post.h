#ifndef POST_H
#define POST_H

#include "content.h"
class Post :public Content
{
    unsigned int RepostCounter,LikeCounter,CommentCounter;
public:
    Post(QString , QString);
};

#endif // POST_H
