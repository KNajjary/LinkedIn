
#include "WelcomeWindow.h"
#include "completeuserinfowindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Welcome Window
    WelcomeWindow ww;
    ww.setStyleSheet("background-color:yellow;");
    ww.setAutoFillBackground(true);
    //while (true){
        ww.show();
    /*if(ww.IsPushButton1Pressed()){
        JoinAndSingInWindow jw;
        jw.show();


    }*/
    //}


    //
    return a.exec();
}
