#ifndef THREADS_H
#define THREADS_H

#include <QObject>
#include <QDebug>
#include <QThread>

class IntroThreadWorker;
class BetweenThreadWorker;

class Threads : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Threads(QObject *parent = nullptr);
    ~Threads();
    Q_INVOKABLE void on_intro();
    Q_INVOKABLE void on_between();
    Q_INVOKABLE void on_manager();
private:
    QThread thread;
    QThread pThread;
    QThread cThread;

    IntroThreadWorker* introThreadWorker;
    BetweenThreadWorker* producer;
    BetweenThreadWorker* consumer;
public slots:


private slots:

signals:

};

#endif // THREADS_H
