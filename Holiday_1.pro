QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    booking.cpp \
    car_rental.cpp \
    customer.cpp \
    fehlermeldung.cpp \
    flight.cpp \
    hotel.cpp \
    main.cpp \
    holiday.cpp \
    travel.cpp \
    travelagency.cpp

HEADERS += \
    booking.h \
    car_rental.h \
    customer.h \
    fehlermeldung.h \
    flight.h \
    holiday.h \
    hotel.h \
    travel.h \
    travelagency.h

FORMS += \
    holiday.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
