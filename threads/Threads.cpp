#include "Threads.h"
/**
 * @brief Threads::Threads.
 * @param parent
 */
Threads::Threads(QObject *parent) : QObject(parent)
{
    qInfo() << "Threads constructed";
}
/**
 * @brief Threads::~Threads
 */
Threads::~Threads()
{
    qInfo() << "Threads deconstructed";
    delete  _introThreadWorker;
}
/**
 * @brief Threads::on_intro
 */
void Threads::on_intro()
{
    _thread.setObjectName("IntroThreadWorker");
    _introThreadWorker->moveToThread(&_thread);

    connect(&_thread, &QThread::started, _introThreadWorker, &IntroThreadWorker::run);
    connect(_introThreadWorker, &IntroThreadWorker::stopThread, &_thread, &QThread::quit);

    _thread.start();
}
