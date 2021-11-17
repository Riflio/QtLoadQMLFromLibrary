#ifndef IUILIBRARY_H
#define IUILIBRARY_H

#include <QObject>
#include "iuiclass.h"


/**
* @brief Интерфейс библиотеки с UI
*/
class IUILibrary: public QObject
{
public:
    virtual ~IUILibrary() = default;
    virtual IUIClass * getMainUI(QObject * parent) = 0;
};
Q_DECLARE_INTERFACE(IUILibrary, "ru.pavelk.uilibrary.interface")

#endif // IUILIBRARY_H
