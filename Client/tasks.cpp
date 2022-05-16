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

void tasks::setCondition() {
    QString resultCondition = "";
    if (task_number == 1) {
        condition = create_condition(task_number);
        resultCondition.append("Для формулы ");
        resultCondition += "(" + condition.mid(0,3) + ")" + condition.mid(3,1) + "(" + condition.mid(4,3) + ") ";
        resultCondition.append("построить таблицу истинностных значений и определить, является ли формула а) общезначимой, б) невыполнимойб в) выполнимой, г) опровержимой. В ответ записать 4 цифры (0 - неявляется или 1 - является) через пробел.");
    }
    else if (task_number == 2) {
        condition = create_condition(task_number);
    }
    else if (task_number == 3) {
        condition = create_condition(task_number);
    }
    else if (task_number == 4) {
        condition = create_condition(task_number);
    }
    ui->textBrw_task->setText(resultCondition);
}

void tasks::set_task_number(int n, QString login){
    task_number = n;
    this->login = login;
    QString show_number = "Task number " + QString::number(n);
    ui->task_number->setText(show_number);
    // input_for_task = generate_input_for_task();
    // generate_text_task();
}

void tasks::on_pushBut_chek_clicked()
{
    QString answer = ui->lineEdit_ans->text();
    QString result = check_answer(login, answer, condition, task_number);
    ui->lineEdit_ans->setText("");
    hide();
}

