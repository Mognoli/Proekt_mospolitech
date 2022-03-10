#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QRunnable>

class Task : public QObject, public QRunnable {
    Q_OBJECT

public:
    Task();

protected:
    void run();

signals:
    void echo(QString echoString);
};

#endif // TASK_H
