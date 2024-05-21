#ifndef POSTUI_H
#define POSTUI_H

#include <QWidget>

namespace Ui {
class PostUi;
}

class PostUi : public QWidget
{
    Q_OBJECT

public:
    explicit PostUi(QWidget *parent = nullptr);
    ~PostUi();

private:
    Ui::PostUi *ui;
};

#endif // POSTUI_H
