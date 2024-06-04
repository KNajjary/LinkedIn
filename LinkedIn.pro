QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcomment.cpp \
    comment.cpp \
    company.cpp \
    completecompanyinfo.cpp \
    completeuserinfowindow.cpp \
    content.cpp \
    conversation.cpp \
    functions.cpp \
    LogAndSignInWindow.cpp \
    main.cpp \
    WelcomeWindow.cpp \
    me.cpp \
    member.cpp \
    message.cpp \
    mydatabase.cpp \
    newpost.cpp \
    person.cpp \
    post.cpp \
    postui.cpp \
    user.cpp \
    verificationwindow.cpp \
    viewprofile.cpp

HEADERS += \
    WelcomeWindow.h \
    addcomment.h \
    comment.h \
    company.h \
    completecompanyinfo.h \
    completeuserinfowindow.h \
    content.h \
    conversation.h \
    functions.h \
    LogAndSignInWindow.h \
    me.h \
    member.h \
    message.h \
    mydatabase.h \
    newpost.h \
    person.h \
    post.h \
    postui.h \
    structs.h \
    user.h \
    verificationwindow.h \
    viewprofile.h

FORMS += \
    WelcomeWindow.ui \
    LogAndSignInWindow.ui \
    addcomment.ui \
    comment.ui \
    completecompanyinfo.ui \
    completeuserinfowindow.ui \
    conversation.ui \
    me.ui \
    message.ui \
    newpost.ui \
    postui.ui \
    verificationwindow.ui \
    viewprofile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
