#include "Threads.h"
#include "IntroThreadWorker.h"
#include "BetweenThreadWorker.h"
#include "ManagerThread.h"

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
}
/**
 * @brief Threads::on_intro
 */
void Threads::on_intro()
{
    introThreadWorker = new class IntroThreadWorker();
    thread.setObjectName("IntroThreadWorker");
    introThreadWorker->moveToThread(&thread);

    connect(&thread, &QThread::started, introThreadWorker, &IntroThreadWorker::run);
    connect(introThreadWorker, &IntroThreadWorker::finished, &thread, &QThread::quit);

    thread.start();
}
/**
 * @brief Threads::on_between
 */
void Threads::on_between()
{
    producer = new class BetweenThreadWorker();
    consumer = new class BetweenThreadWorker();

    producer->moveToThread(&pThread);
    consumer->moveToThread(&cThread);

    producer->setProducer(true);

    pThread.setObjectName("Producer thread");
    cThread.setObjectName("Consumer thread");

    producer->setObjectName("Producer");
    consumer->setObjectName("Consumer");

    connect(&pThread, &QThread::started, producer, &BetweenThreadWorker::run);
    connect(&cThread, &QThread::started, consumer, &BetweenThreadWorker::run);

    connect(producer, &BetweenThreadWorker::produced, consumer, &BetweenThreadWorker::consume);
    connect(producer, &BetweenThreadWorker::finished, consumer, &BetweenThreadWorker::quit);

    cThread.start();
    pThread.start();
}
/**
 * @brief Threads::on_manager
 */
void Threads::on_manager()
{
    ManagerThread manager;
    manager.start();
}
