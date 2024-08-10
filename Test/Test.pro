QT += testlib
QT -= gui

TEMPLATE = app
CONFIG += testcase
QT += testlib



CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test.cpp
#SOURCES += ../travelagency.h
#SOURCES += ../travelagency.cpp

