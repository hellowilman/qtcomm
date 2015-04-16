#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T11:56:17
#
#-------------------------------------------------

QT += core
QT += network
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = comm_sample
TEMPLATE = app


SOURCES += main.cpp\
    commmodule.cpp \
    test_comm.cpp


HEADERS  += commmodule.h \
    test_comm.h

