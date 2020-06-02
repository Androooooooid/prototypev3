#-------------------------------------------------
#
# Project created by QtCreator 2019-10-30T12:40:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prototypev3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loggingcategories.cpp \
    mysetting.cpp

HEADERS  += mainwindow.h \
    loggingcategories.h \
    mysetting.h

TRANSLATIONS = QtLanguage_en.ts \
               QtLanguage_ru.ts \
               QtLanguage_de.ts \
               QtLanguage_cn.ts

FORMS    += mainwindow.ui
