#include "tasks.h"
#include "ui_tasks.h"
#include "functionforclient.h"

tasks::tasks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tasks)
{
    ui->setupUi(this);
}

tasks::~tasks()
{
    delete ui;
}

void tasks::set_task_number(int n){
    task_number = n;
    QString show_number = "Task number " + QString::number(n);
    ui->task_number->setText(show_number);
    // input_for_task = generate_input_for_task();
    // generate_text_task();
}

void tasks::on_pushBut_chek_clicked()
{
    QString answer = ui->lineEdit_ans->text();
    check_answer(answer, input_for_task, task_number);
    ui->lineEdit_ans->setText("");
    hide();
}

