#ifndef INTROTHREADWORKER_H
#define INTROTHREADWORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>

class IntroThreadWorker : public QObject
{
    Q_OBJECT

public:
    explicit IntroThreadWorker(QObject *parent = nullptr);
    ~IntroThreadWorker();

private:

public slots:
    void run();

private slots:

signals:
    void stopThread();
};

#endif // INTROTHREADWORKER_H
