#include "appcore.h"
#include <QDebug>

AppCore::AppCore(QObject *parent) : QObject(parent), _uiLib(nullptr), _uiMainClass(nullptr)
{

}

const QString& AppCore::uiMainPath() const
{
    return _uiMainPath;
}

void AppCore::setUIMainPath(const QString& newUIiMainPath)
{
    if ( _uiMainPath==newUIiMainPath ) { return; }
    _uiMainPath = newUIiMainPath;
    emit uiMainPathChanged();
}



/**
* @brief Подгружаем библиотеку и задаём основные свойства
* @param path
* @return
*/
bool AppCore::loadUILibrary(QUrl path)
{
    qDebug()<<"Go loadUILibrary from"<<path;
    QFile libFile(path.toLocalFile());


    if ( !libFile.exists()  ) {
        qWarning()<<"---file does not exists!";
        return false;
    }

    QPluginLoader lib(libFile.fileName());

    if ( !lib.load() ) {
        qWarning()<<"---unable load library, error:"<<lib.errorString();
        return false;
    }

    _uiLib = dynamic_cast<IUILibrary*>(lib.instance());

    _uiMainClass = _uiLib->getMainUI(this);

    setUIMainPath(_uiMainClass->uiPath());

    qDebug()<<"Library loaded!";

    return true;
}



