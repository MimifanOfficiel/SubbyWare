QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/popupsdialog.cpp \
    src/presetconfigurations.cpp \
    src/addpresetdialog.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/modifypresetdialog.cpp \
    src/preset.cpp

HEADERS += \
    includes/addpresetdialog.hpp \
    includes/mainwindow.hpp \
    includes/modifypresetdialog.hpp \
    includes/preset.hpp \
    includes/presetConfigurations.hpp \
    includes/popupsdialog.hpp

FORMS += \
    forms/addpresetdialog.ui \
    forms/mainwindow.ui \
    forms/modifypresetdialog.ui \
    forms/popupsdialog.ui

TRANSLATIONS += \
    SubbyWare_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
