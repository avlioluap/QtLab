#include "ManagerThread.h"

/**
 * @brief ManagerThread::ManagerThread
 * @param parent
 */
ManagerThread::ManagerThread(QObject *parent)
{
    Q_UNUSED(parent)
    qInfo() << "ManagerThread created" << QThread::currentThread();
}
/**
 * @brief ManagerThread::start
 */
void ManagerThread::start()
{
    for(int i = 0; i < 2; i++)
    {
        ManagerThreadWorker *worker = new ManagerThreadWorker();
        worker->setAutoDelete(true);

        connect(worker, &ManagerThreadWorker::started, this, &ManagerThread::started, Qt::QueuedConnection);
        connect(worker, &ManagerThreadWorker::finished, this, &ManagerThread::finished, Qt::QueuedConnection);
        connect(this, &ManagerThread::work, worker, &ManagerThreadWorker::work, Qt::QueuedConnection);

        QThreadPool::globalInstance()->start(worker);
    }
}
/**
 * @brief ManagerThread::started
 */
void ManagerThread::started()
{
    ManagerThreadWorker* worker = qobject_cast<ManagerThreadWorker*>(sender());
    if (!worker) return;

    qInfo() << "ManagerThread started" << QThread::currentThread();

    // tell the worker to work
    //emit work();

}
/**
 * @brief ManagerThread::finished
 */
void ManagerThread::finished()
{
    ManagerThreadWorker* worker = qobject_cast<ManagerThreadWorker*>(sender());
    if (!worker) return;

    qInfo() << "ManagerThread finished" << QThread::currentThread();
}
