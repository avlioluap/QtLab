#ifndef BETWEENTHREADWORKER_H
#define BETWEENTHREADWORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QRandomGenerator>

class BetweenThreadWorker : public QObject
{
    Q_OBJECT
public:
    explicit BetweenThreadWorker(QObject *parent = nullptr);
    ~BetweenThreadWorker();

    bool producer() const;
    void setProducer(bool newProducer);

private:
    QTimer* m_timer;
    bool m_producer;
    int m_count;

public slots:
    void consume(int value);
    void run();
    void quit();

private slots:
    void timeout();

signals:
    void produced(int value);
    void finished();
};

#endif // BETWEENTHREADWORKER_H
