#include "uimainclass.h"
#include <QDebug>

UIMainClass::UIMainClass(QObject *parent) : QObject(parent)
{

}

QString UIMainClass::uiPath() const
{
    return "qrc:/uiMain.qml";
}
