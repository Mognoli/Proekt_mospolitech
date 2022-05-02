#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_auth_reg = new auth_reg;
    ui_tasks = new tasks;
    ui_stat = new Statistics;
    ui_auth_reg->show();
    connect(ui_auth_reg, &auth_reg::authorization_completed, this, &MainWindow::slot_show);
}

MainWindow::~MainWindow()
{
    delete ui_auth_reg;
    delete ui_tasks;
    delete ui_stat;
    delete ui;
}

void MainWindow::slot_show(QString login){
    QString show_login = "User: " + login;
    ui->label->setText(show_login);
    show();
}

void MainWindow::on_pushBut_t1_clicked()
{
    ui_tasks->set_task_number(1);
    ui_tasks->setWindowModality(Qt::ApplicationModal);
    ui_tasks->show();
}


void MainWindow::on_pushBut_t2_clicked()
{
    ui_tasks->set_task_number(2);
    ui_tasks->setWindowModality(Qt::ApplicationModal);
    ui_tasks->show();
}


void MainWindow::on_pushBut_t3_clicked()
{
    ui_tasks->set_task_number(3);
    ui_tasks->setWindowModality(Qt::ApplicationModal);
    ui_tasks->show();
}


void MainWindow::on_pushBut_t4_clicked()
{
    ui_tasks->set_task_number(4);
    ui_tasks->setWindowModality(Qt::ApplicationModal);
    ui_tasks->show();
}


void MainWindow::on_actionTask_1_triggered()
{
    MainWindow::on_pushBut_t1_clicked();
}


void MainWindow::on_actionTask_2_triggered()
{
    MainWindow::on_pushBut_t2_clicked();
}


void MainWindow::on_actionTask_3_triggered()
{
    MainWindow::on_pushBut_t3_clicked();
}


void MainWindow::on_actionTask_4_triggered()
{
    MainWindow::on_pushBut_t4_clicked();
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

void MainWindow::on_actionExit_triggered()
{
    MainWindow::on_pushButton_exit_clicked();
}

void MainWindow::on_pushBut_stat_clicked()
{
    QString userPlus = ui->label->text();
    QStringList user = userPlus.split(QLatin1Char(' '));
    QString login = user.at(1);
    ui_stat->StartUiStat(login);
    ui_stat->setWindowModality(Qt::ApplicationModal);
    ui_stat->show();
}


void MainWindow::on_actionStatistics_triggered()
{
    MainWindow::on_pushBut_stat_clicked();
}

