#ifndef THREADS_H
#define THREADS_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include "IntroThreadWorker.h"

class Threads : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Threads(QObject *parent = nullptr);
    ~Threads();
    Q_INVOKABLE void on_intro();
private:
    QThread _thread;
    IntroThreadWorker* _introThreadWorker = new IntroThreadWorker();

public slots:


private slots:

signals:

};

#endif // THREADS_H
