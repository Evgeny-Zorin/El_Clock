QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    class_changehistory.cpp \
    main.cpp \
    myclockwindow.cpp

HEADERS += \
    class_changehistory.h \
    myclockwindow.h

FORMS += \
    myclockwindow.ui

TRANSLATIONS += \
    Clock_Zor_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
