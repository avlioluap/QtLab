#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>

class MainWindow Q_DECL_FINAL : public QObject
{
    Q_OBJECT

public:
    explicit MainWindow(QObject *parent = nullptr);
    ~MainWindow();

    void registerTypes();
private:

signals:

};

#endif // MAINWINDOW_H
