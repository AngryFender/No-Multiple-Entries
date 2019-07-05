#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <checktext.h>
#include <QObject>
#include <QMetaObject>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));




    QObject* rootObject = static_cast<QObject*>(engine.rootObjects()[0]);
    checkText checkTexts(nullptr,rootObject);
    if (engine.rootObjects().isEmpty())
        return -1;


    QObject::connect(rootObject, SIGNAL(qmlSignal(QString)),
                         &checkTexts, SLOT(cppSlot(QString)));




    return app.exec();
}
