#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QUrl>
#include <QFile>
#include <QPluginLoader>

#include "iuilibrary.h"

class AppCore : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString uiMainPath READ uiMainPath NOTIFY uiMainPathChanged)

public:
    explicit AppCore(QObject *parent = nullptr);

    const QString& uiMainPath() const;
    void setUIMainPath(const QString& newUIMainPath);

public slots:
    bool loadUILibrary(QUrl path);

signals:
    void uiMainPathChanged();

private:
    QString _uiMainPath;

    IUILibrary * _uiLib;
    IUIClass * _uiMainClass;
};

#endif // APPCORE_H
