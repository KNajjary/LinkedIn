
#include "WelcomeWindow.h"
#include "completeuserinfowindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Welcome Window

     WelcomeWindow ww;
    //ww.setStyleSheet("background-color:yellow;");
    ww.setAutoFillBackground(true);
    //while (true){
        ww.show();


    /*CompleteUserInfoWindow cw;
        cw.show();

    VerificationWindow vw;
        vw.show();

    LogAndSignInWindow lw;
    lw.show();*/


    //}


    //
    return a.exec();
}
