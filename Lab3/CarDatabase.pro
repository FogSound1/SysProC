QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Car.cpp \
    Database.cpp \
    demotecarwindow.cpp \
    disablecarwindow.cpp \
    enablecarwindow.cpp \
    fileoperationswindow.cpp \
    listactivecarswindow.cpp \
    listallcarswindow.cpp \
    listinactivecarswindow.cpp \
    main.cpp \
    mainwindow.cpp \
    promotecarwindow.cpp

HEADERS += \
    Car.h \
    Database.h \
    demotecarwindow.h \
    disablecarwindow.h \
    enablecarwindow.h \
    fileoperationswindow.h \
    listactivecarswindow.h \
    listallcarswindow.h \
    listinactivecarswindow.h \
    mainwindow.h \
    promotecarwindow.h

FORMS += \
    demotecarwindow.ui \
    disablecarwindow.ui \
    enablecarwindow.ui \
    fileoperationswindow.ui \
    listactivecarswindow.ui \
    listallcarswindow.ui \
    listinactivecarswindow.ui \
    mainwindow.ui \
    promotecarwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
