QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cc \
    model.cc \
    credit.cc \
    main.cc \
    qcustomplot.cc \
    view.cc

HEADERS += \
    controller.h \
    helpers/calculation.h \
    helpers/operations.h \
    model.h \
    config.h \
    config.h.in \
    credit.h \
    qcustomplot.h \
    view.h

FORMS += \
    credit.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
