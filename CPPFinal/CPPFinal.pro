QT += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buildcomputer.cpp \
    computercase.cpp \
    cpu.cpp \
    database.cpp \
    gpu.cpp \
    main.cpp \
    mainwindow.cpp \
    powersupply.cpp \
    ram.cpp

HEADERS += \
    buildcomputer.h \
    computercase.h \
    cpu.h \
    database.h \
    gpu.h \
    mainwindow.h \
    powersupply.h \
    ram.h

FORMS += \
   mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
