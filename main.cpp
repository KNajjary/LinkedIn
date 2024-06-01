
#include "WelcomeWindow.h"
#include "addcomment.h"
#include "completecompanyinfo.h"
#include "completeuserinfowindow.h"
#include <QApplication>
#include "mydatabase.h"
#include "newpost.h"
#include "me.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //WelcomeWindow ww;
    //ww.setStyleSheet("background-color:yellow;");
    //ww.setAutoFillBackground(true);
    //ww.show();
    //NewPost con;
    //con.show();
    //MyDatabase d;
    //d.CreatePostsTable();
    //d.CreatePostsTable("Ali");
    //CompleteCompanyInfo w("fg");
    //w.show();
    //Post p("Ali","Hi!!!!!!","tgfhxpicture",1);
    //AddComment * c=new AddComment("Ali/Posts","Ali",1);
    //c->show();
    Me * me=new Me("fg");
    me->show();

    /*CompleteUserInfoWindow cw;
    cw.show();*/

    /*VerificationWindow vw;
        vw.show();
*/
    //LogAndSignInWindow lw;
    //lw.show();


    //}


    //
    return a.exec();
}
