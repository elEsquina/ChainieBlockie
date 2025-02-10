#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
// #include "blockchainmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // qmlRegisterType<BlockchainManager>("com.example", 1, 0, "BlockchainManager");


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("myapp", "Main");

    return app.exec();
}
