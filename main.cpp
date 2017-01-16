#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QDir>

#include "sandboxitemmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    SandBoxItemModel* sandBoxModel = new SandBoxItemModel();
    sandBoxModel->setSandBoxDetails(QDir::currentPath());   //show current path

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("sandBoxModel", sandBoxModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
