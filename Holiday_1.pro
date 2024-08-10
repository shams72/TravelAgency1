QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    New_Customer.cpp \
    abc_analyse.cpp \
    airport.cpp \
    algorithmen.cpp \
    booking.cpp \
    car_rental.cpp \
    checkui.cpp \
    customer.cpp \
    flight.cpp \
    hotel.cpp \
    main.cpp \
    holiday.cpp \
    options.cpp \
    sortfunktor.cpp \
    travel.cpp \
    travelagency.cpp

HEADERS += \
    New_Customer.h \
    abc_analyse.h \
    airport.h \
    booking.h \
    car_rental.h \
    checkui.h \
    customer.h \
    flight.h \
    graph.h \
    holiday.h \
    hotel.h \
    options.h \
    sortfunktor.h \
    travel.h \
    travelagency.h

FORMS += \
    New_Customer.ui \
    abc_analyse.ui \
    checkui.ui \
    holiday.ui \
    options.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
