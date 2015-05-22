#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T19:26:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SansCar
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    window.cpp \
    cadastrarcor.cpp \
    cadastrarcidade.cpp \
    cadastrarestado.cpp \
    cadastrarcarro.cpp \
    controllerfile.cpp \
    carromodel.cpp \
    cadastrarmarca.cpp \
    cadastrarmodelo.cpp \
    cadastrarnovouser.cpp \
    pagamento.cpp \
    mensagemdecadastro.cpp

HEADERS  += dialog.h \
    window.h \
    cadastrarcor.h \
    cadastrarcidade.h \
    cadastrarestado.h \
    cadastrarcarro.h \
    controllerfile.h \
    carromodel.h \
    cadastrarmarca.h \
    cadastrarmodelo.h \
    Configs.h \
    cadastrarnovouser.h \
    pagamento.h \
    mensagemdecadastro.h

FORMS    += dialog.ui \
    window.ui \
    cadastrarcor.ui \
    cadastrarcidade.ui \
    cadastrarestado.ui \
    cadastrarcarro.ui \
    cadastrarmarca.ui \
    cadastrarmodelo.ui \
    cadastrarnovouser.ui \
    pagamento.ui \
    mensagemdecadastro.ui

RESOURCES += \
    Icons.qrc
