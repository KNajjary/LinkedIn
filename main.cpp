
#include "WelcomeWindow.h"
#include "addcomment.h"
#include "completecompanyinfo.h"
#include "completeuserinfowindow.h"
#include <QApplication>
#include "jobui.h"
#include "mydatabase.h"
#include "newjob.h"
#include "newpost.h"
#include "me.h"
#include "viewprofile.h"
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
    //qDebug()<< d.SelectMax("Ali_Posts","RowNumber");
    //d.CreatePostsTable();
    //d.CreatePostsTable("Ali");
    //CompleteCompanyInfo w("fg");
    //w.show();
    //Post p("Ali","Hi!!!!!!","tgfhxpicture",1);
    //AddComment * c=new AddComment("Ali/Posts","Ali",1);
    //c->show();
    //Me * me=new Me("fg");
    //me->show();
    //ViewProfile vp("Ali");
    //vp.show();
    //NewJob nj("Ali");
    //nj.show();
    JobUi jui("Ali",6,"kosar");
    jui.show();
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
