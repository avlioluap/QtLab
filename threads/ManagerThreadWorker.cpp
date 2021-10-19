#include "ManagerThreadWorker.h"

/**
 * @brief ManagerThreadWorker::ManagerThreadWorker
 * @param parent
 */
ManagerThreadWorker::ManagerThreadWorker(QObject *parent)
{
    Q_UNUSED(parent)
    qInfo() << "ManagerThreadWorker created" << QThread::currentThread();
}
/**
 * @brief ManagerThreadWorker::~ManagerThreadWorker
 */
ManagerThreadWorker::~ManagerThreadWorker()
{
    qInfo() << "ManagerThreadWorker destroyed" << QThread::currentThread();
}
/**
 * @brief ManagerThreadWorker::run
 */
void ManagerThreadWorker::run()
{
    qInfo() << "ManagerThreadWorker starting" << QThread::currentThread();

    emit started();

    for(int i =0; i < 5; i++)
    {
        qInfo() << "ManagerThreadWorker running" << QThread::currentThread();
        QThread::currentThread()->msleep(1000);
    }

    qInfo() << "ManagerThreadWorker finishing" << QThread::currentThread();

    emit finished();
}
/**
 * @brief ManagerThreadWorker::work
 */
void ManagerThreadWorker::work()
{
    qInfo() << "ManagerThreadWorker work" << QThread::currentThread();
}
