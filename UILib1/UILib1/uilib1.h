#ifndef UILIB1_H
#define UILIB1_H

#include "UILib1_global.h"

#include "iuilibrary.h"
#include "uimainclass.h"

class UILIB1_EXPORT UILib1: public IUILibrary
{
    Q_OBJECT
    Q_INTERFACES(IUILibrary)
    Q_PLUGIN_METADATA(IID "ru.pavelk.uilibrary.interface" FILE "uilibraryinterface.json") //-- Задаём для какого интерфейса из каких файлов брать дополнительную инфу
public:
    UILib1();

    IUIClass * getMainUI(QObject * parent) override;


};

#endif // UILIB1_H
