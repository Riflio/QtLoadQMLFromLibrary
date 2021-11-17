#include "uilib1.h"
#include <QDebug>


UILib1::UILib1()
{
    qDebug()<<"UILib1 constructor";
}

IUIClass* UILib1::getMainUI(QObject* parent)
{
    qDebug()<<"Construct UI Main class";
    return new UIMainClass(parent);
}

