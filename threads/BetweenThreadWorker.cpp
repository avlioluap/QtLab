#include "BetweenThreadWorker.h"

/**
 * @brief BetweenThreadWorker::BetweenThreadWorker
 * @param parent
 */
BetweenThreadWorker::BetweenThreadWorker(QObject *parent) : QObject(parent)
{
    qInfo() << "BetweenThreadWorker constructed" << QThread::currentThread();
    m_producer  = false;
    m_count     = 0;
}
/**
 * @brief BetweenThreadWorker::~BetweenThreadWorker
 */
BetweenThreadWorker::~BetweenThreadWorker()
{
    qInfo() << "BetweenThreadWorker deconstructed" << QThread::currentThread();
}
/**
 * @brief BetweenThreadWorker::producer
 * @return
 */
bool BetweenThreadWorker::producer() const
{
    return m_producer;
}
/**
 * @brief BetweenThreadWorker::setProducer
 * @param newProducer
 */
void BetweenThreadWorker::setProducer(bool newProducer)
{
    m_producer = newProducer;
}
/**
 * @brief BetweenThreadWorker::consume
 * @param value
 */
void BetweenThreadWorker::consume(int value)
{
    qInfo() << "Consuming" << value << QThread::currentThread();
}
/**
 * @brief BetweenThreadWorker::run
 */
void BetweenThreadWorker::run()
{
    qInfo() << "Starting" << QThread::currentThread();

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &BetweenThreadWorker::timeout);

    if (m_producer)
    {
        qInfo() << "Starting timer" << QThread::currentThread();

        m_timer->setInterval(1000);
        m_timer->start();
    }
}
/**
 * @brief BetweenThreadWorker::quit
 */
void BetweenThreadWorker::quit()
{
    qInfo() << "Quitting" << QThread::currentThread();

    m_timer->stop();

    emit finished();
}
/**
 * @brief BetweenThreadWorker::timeout
 */
void BetweenThreadWorker::timeout()
{
    int value = QRandomGenerator::global()->bounded(1000);

    qInfo() << "Producing" << value << QThread::currentThread();

    emit produced(value);

    m_count++;

    if (m_count == 5)
        quit();
}
