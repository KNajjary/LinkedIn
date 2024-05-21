#include "post.h"

Post::Post(QString t, QString p)
{
    SetText(t);
    SetPicture(p);
    SetTimeSent();
}
