QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ut_b_e.cpp \
    ../Zad_B_E/f1f.cpp

HEADERS += \
    ../Zad_B_E/f1f.h

DISTFILES += \
    ../build-Zad_B_E-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/Zad_B_E.exe \
    ../build-Zad_B_E-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/f1f.obj \
    ../build-Zad_B_E-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/main.obj
