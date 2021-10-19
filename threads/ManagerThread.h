#ifndef MANAGERTHREAD_H
#define MANAGERTHREAD_H

#include <QObject>
#include <QThreadPool>
#include <QRunnable>
#include <QThread>
#include <QDebug>
#include "ManagerThreadWorker.h"

class ManagerThread : public QObject
{
    Q_OBJECT
public:
    explicit ManagerThread(QObject *parent = nullptr);

public slots:
    void start();
    void started();
    void finished();

signals:
    void work(); // not the best way
};

#endif // MANAGERTHREAD_H
