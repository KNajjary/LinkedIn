QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcomment.cpp \
    applylist.cpp \
    applyview.cpp \
    comment.cpp \
    company.cpp \
    completecompanyinfo.cpp \
    completeuserinfowindow.cpp \
    connectionreqicon.cpp \
    content.cpp \
    conversation.cpp \
    functions.cpp \
    LogAndSignInWindow.cpp \
    home.cpp \
    job.cpp \
    jobicon.cpp \
    jobui.cpp \
    like.cpp \
    main.cpp \
    WelcomeWindow.cpp \
    me.cpp \
    member.cpp \
    message.cpp \
    mydatabase.cpp \
    mynetwork_company.cpp \
    mynetwork_person.cpp \
    newjob.cpp \
    newpost.cpp \
    person.cpp \
    post.cpp \
    postui.cpp \
    profileicon.cpp \
    root.cpp \
    user.cpp \
    verificationwindow.cpp \
    viewjobs_company.cpp \
    viewjobs_person.cpp \
    viewprofile.cpp

HEADERS += \
    WelcomeWindow.h \
    addcomment.h \
    applylist.h \
    applyview.h \
    comment.h \
    company.h \
    completecompanyinfo.h \
    completeuserinfowindow.h \
    connectionreqicon.h \
    content.h \
    conversation.h \
    functions.h \
    LogAndSignInWindow.h \
    home.h \
    job.h \
    jobicon.h \
    jobui.h \
    like.h \
    me.h \
    member.h \
    message.h \
    mydatabase.h \
    mynetwork_company.h \
    mynetwork_person.h \
    newjob.h \
    newpost.h \
    person.h \
    post.h \
    postui.h \
    profileicon.h \
    root.h \
    structs.h \
    user.h \
    verificationwindow.h \
    viewjobs_company.h \
    viewjobs_person.h \
    viewprofile.h

FORMS += \
    WelcomeWindow.ui \
    LogAndSignInWindow.ui \
    addcomment.ui \
    applylist.ui \
    applyview.ui \
    comment.ui \
    completecompanyinfo.ui \
    completeuserinfowindow.ui \
    connectionreqicon.ui \
    conversation.ui \
    home.ui \
    jobicon.ui \
    jobui.ui \
    me.ui \
    message.ui \
    mynetwork_company.ui \
    mynetwork_person.ui \
    newjob.ui \
    newpost.ui \
    postui.ui \
    profileicon.ui \
    root.ui \
    verificationwindow.ui \
    viewjobs_company.ui \
    viewjobs_person.ui \
    viewprofile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
