#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <MainWindow.h>
#include <QThread>
#include <threads/Threads.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QThread::currentThread()->setObjectName("Main thread");

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);


    QQmlContext* rootContext = engine.rootContext();

    Threads threads;
    rootContext->setContextProperty("cThreads", &threads);


    MainWindow g_MainWindow;
    g_MainWindow.registerTypes();

    return app.exec();
}
