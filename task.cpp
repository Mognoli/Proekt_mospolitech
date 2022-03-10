#include "task.h"
#include <QDebug>
#include <QMetaType>

Task::Task()
{
    qRegisterMetaType<qintptr>("qintptr");
}

// для выполнения этой задачи создается отдельный thread, который не занимает время main thread, а после окончанию передает результат в main thread
// run - это процесс, который запускается QRunnable (?) QThreadPool::globalInstance()->start<задача>
// задача, затрачивающая какое то время, требующая асинхронное исполнение (не является необходимым для echo сервера, но может потребоваться в дальнейшем)
void Task::run() {
    qDebug() << "task...";
    QString echoString = "testing..";

    // посылает сигнал echo когда выполнение run закончено
    // this thread calling emit when ended
    emit echo(echoString);

}
