#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T13:33:23
#
#-------------------------------------------------

QT       += core gui
QT       += webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IDEPseudoD
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    intabtextedit.cpp \
    pseudodsyntaxhighlighter.cpp \
    ejecutor.cpp \
    ejecutor_config.cpp \
    viewhtml.cpp \
    maineventfilter.cpp \
    aboutwindow.cpp

HEADERS  += mainwindow.h \
    intabtextedit.h \
    pseudodsyntaxhighlighter.h \
    ejecutor.h \
    ejecutor_config.h \
    viewhtml.h \
    maineventfilter.h \
    aboutwindow.h

FORMS    += mainwindow.ui \
    intabtextedit.ui \
    ejecutor.ui \
    ejecutor_config.ui \
    viewhtml.ui \
    aboutwindow.ui
