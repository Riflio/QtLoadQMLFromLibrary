#ifndef IUICLASS_H
#define IUICLASS_H

#include <QString>

/**
* @brief Интерфейс классов UI
*/
class IUIClass
{
public:
    virtual ~IUIClass() {}

    virtual QString uiPath() const =0;

};


#endif // IUICLASS_H
