
#include "WelcomeWindow.h"
#include "addcomment.h"
#include "applylist.h"
#include "applyview.h"
#include "completecompanyinfo.h"
#include "completeuserinfowindow.h"
#include <QApplication>
#include "home.h"
#include "jobicon.h"
#include "jobui.h"
#include "mydatabase.h"
#include "mynetwork_company.h"
#include "mynetwork_person.h"
#include "newjob.h"
#include "newpost.h"
#include "me.h"
#include "profileicon.h"
#include "root.h"
#include "viewjobs_company.h"
#include "viewjobs_person.h"
#include "viewprofile.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WelcomeWindow ww;
    //ww.setStyleSheet("background-color:yellow;");
    //ww.setAutoFillBackground(true);
    ww.show();
    //NewPost con;
    //con.show();
    //MyDatabase d;
    //qDebug()<<d.DoesExist("Ali_Followers","Username","moo");
    //d.CreateConnectionsTable("Ali_Connections");
    //d.CreateConnectingsTable("Ali_Connectings");
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
    //ViewJobs_Company jui("Ali");
    //jui.show();
    //ProfileIcon p("Ali","rt");
    //p.show();
    //MyNetwork_Person n("Ali");
    //n.show();
    //ApplyList al("Ali",6);
    //al.show();
    //ApplyView av("Ali_Job_6_Applys",1);
    //av.show();
    //PostUi p("Ali",1,"rt");
    //p.show();
    //MyDatabase db;
    //qDebug()<<db.GetNumberOfRowsWhere("Users","Career","nurs");

    //db.InsertLike("Ali_Post1_Likes","Username","TimeSenttoString");
    //MyDatabase db;
    //db.Update("Ali_Posts","RowNumber",1,"RepostCounter",2);
    /*CompleteUserInfoWindow cw;
    cw.show();*/

    /*VerificationWindow vw;
        vw.show();
*/
    //Home h("rt");
    //h.show();
    //LogAndSignInWindow lw;
    //lw.show();
    //Root h("user1");
    //h.show();
    //ApplyList al("Ali",7);
    //al.show();
    ///
    ///
    //}
    //AddComment ad("rt",1,"Ali");
    //ad.show();
    //ViewJobs_Person h("user1");
    //h.show();
    //
    return a.exec();
}
