#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "appcore.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    app.setOrganizationName("PavelK");
    app.setOrganizationDomain("PavelK.ru");

    QQmlApplicationEngine engine;

    AppCore * core = new AppCore(nullptr);

    engine.rootContext()->setContextProperty("appCore", core);

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) { QCoreApplication::exit(-1); }
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
