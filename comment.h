#ifndef COMMENT_H
#define COMMENT_H

#include "content.h"
#include <QWidget>

namespace Ui {
class Comment;
}

class Comment : public QWidget , public Content
{
    Q_OBJECT

public:
    explicit Comment(QString ,QString, QString ,QString ,QWidget *parent = nullptr);
    ~Comment();

private:
    Ui::Comment *ui;
    QString TableName;
};

#endif // COMMENT_H
