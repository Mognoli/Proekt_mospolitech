#include "statistics.h"
#include "ui_statistics.h"
#include "functionforclient.h"

Statistics::Statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::StartUiStat(QString login){
    ui->ForLogin->setText("User \"" + login + "\" statistics");
    QString statistics = read_statistics(login);
    QStringList stat = statistics.split(QLatin1Char(' '));
    stat.pop_front();
    int count = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<2; j++) {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(stat.at(count)));
                count++;
        }
    }
    count = 0;
    for (int i=0; i<4; i++) {
        int wrong = stat.at(count).toInt() - stat.at(count+1).toInt();
        count += 2;
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(wrong)));
    }
    count = 0;
    for (int i=0; i<4; i++) {
        double proc = 0;
        if (stat.at(count).toInt() != 0)
            proc = (stat.at(count+1).toDouble() / stat.at(count).toInt()) * 100;
        count += 2;
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(proc)));
    }
}


void Statistics::on_pushButton_Exit_clicked()
{
    close();
}

