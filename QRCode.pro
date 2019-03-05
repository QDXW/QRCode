#-------------------------------------------------
#
# Project created by QtCreator 2017-09-19T17:01:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRCode
TEMPLATE = app

DEFINES += HAVE_CONFIG_H

INCLUDEPATH +=QRCodelib\
              CRC


SOURCES += main.cpp\
        mainwindow.cpp \
    QRCodelib/bitstream.c \
    QRCodelib/mask.c \
    QRCodelib/mmask.c \
    QRCodelib/mqrspec.c \
    QRCodelib/qrencode.c \
    QRCodelib/qrinput.c \
    QRCodelib/qrspec.c \
    QRCodelib/rscode.c \
    QRCodelib/split.c \
    CRC/CRC16.c \
    password.cpp

HEADERS  += mainwindow.h \
    QRCodelib/bitstream.h \
    QRCodelib/mask.h \
    QRCodelib/mmask.h \
    QRCodelib/mqrspec.h \
    QRCodelib/qrencode.h \
    QRCodelib/qrencode_inner.h \
    QRCodelib/qrinput.h \
    QRCodelib/qrspec.h \
    QRCodelib/rscode.h \
    QRCodelib/split.h \
    QRCodelib/config.h \
    CRC/Common.h \
    CRC/CRC16.h \
    password.h

FORMS    += mainwindow.ui \
    password.ui

RESOURCES += \
    image.qrc

RC_FILE += res.rc


