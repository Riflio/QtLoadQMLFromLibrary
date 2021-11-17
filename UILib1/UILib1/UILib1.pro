CONFIG += plugin

TEMPLATE = lib
DEFINES += UILIB1_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    uilib1.cpp \
    uimainclass.cpp

HEADERS += \
    UILib1_global.h \
    iuiclass.h \
    iuilibrary.h \
    uilib1.h \
    uimainclass.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    uilibraryinterface.json

RESOURCES += \
    qml.qrc
