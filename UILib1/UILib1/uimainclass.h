#ifndef UIMAINCLASS_H
#define UIMAINCLASS_H

#include <QObject>
#include "iuilibrary.h"

class UIMainClass : public QObject, public IUIClass
{
    Q_OBJECT
public:
    explicit UIMainClass(QObject *parent = nullptr);

    QString uiPath() const override;

signals:

};

#endif // UIMAINCLASS_H
