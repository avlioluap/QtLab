#include "IntroThreadWorker.h"

/**
 * @brief IntroThreadWorker::IntroThreadWorker
 * @param parent
 */
IntroThreadWorker::IntroThreadWorker(QObject *parent) : QObject(parent)
{
    qInfo() << "IntroThreadWorker constructed" << QThread::currentThread();
}
/**
 * @brief IntroThreadWorker::~IntroThreadWorker
 */
IntroThreadWorker::~IntroThreadWorker()
{
    qInfo() << "IntroThreadWorker deconstructed" << QThread::currentThread();
}
/**
 * @brief IntroThreadWorker::run
 */
void IntroThreadWorker::run()
{
    for (int i = 0; i < 5; ++i)
    {
        qInfo() << "IntroThreadWorker working" << QString::number(i) << QThread::currentThread();

        QThread::currentThread()->msleep(500);
    }

    emit stopThread();
}
