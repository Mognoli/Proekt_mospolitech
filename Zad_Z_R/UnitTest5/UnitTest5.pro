QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test5.cpp \
    ../Task5.cpp

HEADERS +=  ../Task5.h
