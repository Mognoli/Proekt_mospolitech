QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += network
CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auth_reg.cpp \
    connecttoserver.cpp \
    functionforclient.cpp \
    main.cpp \
    mainwindow.cpp \
    tasks.cpp

HEADERS += \
    ConnectServer.h \
    auth_reg.h \
    connecttoserver.h \
    functionforclient.h \
    mainwindow.h \
    tasks.h

FORMS += \
    auth_reg.ui \
    mainwindow.ui \
    tasks.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
