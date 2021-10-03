#ifndef INTROWORKER_H
#define INTROWORKER_H

#include <QObject>

class IntroWorker : public QObject
{
    Q_OBJECT
public:
    explicit IntroWorker(QObject *parent = nullptr);

signals:

};

#endif // INTROWORKER_H
