#include "auth_reg.h"
#include "ui_auth_reg.h"
#include "QString"
#include "functionforclient.h"

auth_reg::auth_reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::auth_reg)
{
    ui->setupUi(this);
    ui->lineEdit_email->setVisible(false);
    ui->pushBut_can->setVisible(false);
    ui->label_status->setText("");
}

auth_reg::~auth_reg()
{
    delete ui;
}

void auth_reg::on_pushBut_reg_clicked()
{
    ui->lineEdit_email->setVisible(true);
    ui->pushBut_can->setVisible(true);
    ui->pushBut_reg->setVisible(false);
    ui->label_status->setText("");
    ui->lineEd_log->setText("");
    ui->lineEd_pass->setText("");
    ui->lineEdit_email->setText("");
    flag = 1;
}


void auth_reg::on_pushBut_can_clicked()
{
    ui->lineEdit_email->setVisible(false);
    ui->pushBut_can->setVisible(false);
    ui->pushBut_reg->setVisible(true);
    ui->label_status->setText("");
    ui->lineEd_log->setText("");
    ui->lineEd_pass->setText("");
    ui->lineEdit_email->setText("");
    flag = 0;
}


void auth_reg::on_pushBut_ok_clicked()
{
    ui->label_status->setText("");
    QString login = ui->lineEd_log->text();
    QString password = ui->lineEd_pass->text();
    if ((login == "") || (password == "")) {
        ui->label_status->setText("Enter all fields");
        ui->label_status->setStyleSheet("color:#ff0000");
    } else {
        if (flag == 0) { // auth
            QString status = auth(login, password);
            if (status == "true") {
                emit authorization_completed(login);
                hide();
            } else if (status == "false") {
                ui->label_status->setVisible(true);
                ui->label_status->setText("Authorization failed");
                ui->label_status->setStyleSheet("color:#ff0000");
            }

        } else if (flag == 1) { // reg
            QString email = ui->lineEdit_email->text();
            if (email == "") {
                ui->label_status->setText("Enter all fields");
                ui->label_status->setStyleSheet("color:#ff0000");
            } else {
                QString status = reg(login, password, email);
                if (status == "true") {
                    ui->label_status->setVisible(true);
                    ui->label_status->setText("Registration completed successfully");
                    ui->label_status->setStyleSheet("color:#00ff00");
                    ui->lineEdit_email->setVisible(false);
                    ui->pushBut_can->setVisible(false);
                    ui->pushBut_reg->setVisible(true);
                    ui->lineEd_log->setText("");
                    ui->lineEd_pass->setText("");
                    ui->lineEdit_email->setText("");
                    flag = 0;
                } else if (status == "false") {
                    ui->label_status->setVisible(true);
                    ui->label_status->setText("Registration NOT completed successfully");
                    ui->label_status->setStyleSheet("color:#ff0000");
                }
            }
        }
    }
}
