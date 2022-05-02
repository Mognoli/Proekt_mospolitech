#ifndef TASKS_H
#define TASKS_H

#include <QWidget>

namespace Ui {
class tasks;
}

class tasks : public QWidget
{
    Q_OBJECT

public:
    explicit tasks(QWidget *parent = nullptr);
    ~tasks();
    void set_task_number(int n);

private slots:
    void on_pushBut_chek_clicked();

private:
    Ui::tasks *ui;
    int task_number;
    QString input_for_task;
};

#endif // TASKS_H
