#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "auth_reg.h"
#include "tasks.h"
#include "statistics.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    auth_reg *ui_auth_reg;
    tasks *ui_tasks;
    Statistics *ui_stat;
    QString login;

private slots:
    void slot_show(QString login);
    void on_pushBut_t1_clicked();
    void on_pushBut_t2_clicked();
    void on_pushBut_t3_clicked();
    void on_pushBut_t4_clicked();
    void on_actionTask_1_triggered();
    void on_actionTask_2_triggered();
    void on_actionTask_3_triggered();
    void on_actionTask_4_triggered();
    void on_pushButton_exit_clicked();
    void on_actionExit_triggered();
    void on_pushBut_stat_clicked();
    void on_actionStatistics_triggered();
};
#endif // MAINWINDOW_H
