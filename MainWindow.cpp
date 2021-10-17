#include "MainWindow.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <threads/Threads.h>
/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QObject *parent) : QObject(parent)
{

}
/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{

}
/**
 * @brief MainWindow::registerTypes
 */
void MainWindow::registerTypes()
{
    //qmlRegisterType< Threads > ("Threads", 1, 0, "IntroThreadWorker");
}
