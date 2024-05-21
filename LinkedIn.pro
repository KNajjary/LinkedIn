QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    completeuserinfowindow.cpp \
    content.cpp \
    conversation.cpp \
    functions.cpp \
    LogAndSignInWindow.cpp \
    main.cpp \
    WelcomeWindow.cpp \
    message.cpp \
    mydatabase.cpp \
    newpost.cpp \
    post.cpp \
    postui.cpp \
    user.cpp \
    verificationwindow.cpp

HEADERS += \
    WelcomeWindow.h \
    completeuserinfowindow.h \
    content.h \
    conversation.h \
    functions.h \
    LogAndSignInWindow.h \
    message.h \
    mydatabase.h \
    newpost.h \
    post.h \
    postui.h \
    structs.h \
    user.h \
    verificationwindow.h

FORMS += \
    WelcomeWindow.ui \
    LogAndSignInWindow.ui \
    completeuserinfowindow.ui \
    conversation.ui \
    message.ui \
    newpost.ui \
    postui.ui \
    verificationwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
