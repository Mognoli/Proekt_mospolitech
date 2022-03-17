QT -= gui
QT += core network

CONFIG += c++11 console
CONFIG -= app_bundle
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# Global variable used to enable/disable output of detailed debug
# information about server workaround
DEFINES += DEBUG_ENV=true

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        functionsforserver.cpp \
        main.cpp \
        mytcpserver.cpp \
        mytcpthread.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    functionsforserver.h \
    mytcpserver.h \
    mytcpthread.h
