#ifndef MANAGERTHREADWORKER_H
#define MANAGERTHREADWORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QRunnable>

class ManagerThreadWorker: public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit ManagerThreadWorker(QObject *parent = nullptr);
    ~ManagerThreadWorker();

public slots:
    void work();

signals:
    void started();
    void finished();

    // QRunnable interface
public:
    void run() Q_DECL_OVERRIDE;
};

#endif // MANAGERTHREADWORKER_H
