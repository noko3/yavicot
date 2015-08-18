#-------------------------------------------------
#
# Project created by QtCreator 2015-08-18T01:26:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yavicot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Model/fsmodel.cpp \
    Model/Types/metadata.cpp \
    Model/Types/audiotrackmetadata.cpp \
    Model/Types/videotrackmetadata.cpp \
    Model/Types/subtitlesmetadata.cpp \
    Model/Types/containermetadata.cpp

HEADERS  += mainwindow.h \
    Model/fsmodel.h \
    Model/Types/metadata.h \
    Model/Types/mediaitem.h \
    Model/Types/audiotrackmetadata.h \
    Model/Types/videotrackmetadata.h \
    Model/Types/subtitlesmetadata.h \
    Model/Types/containermetadata.h

FORMS    += mainwindow.ui
