#ifndef AUTH_REG_H
#define AUTH_REG_H

#include <QWidget>

namespace Ui {
class auth_reg;
}

class auth_reg : public QWidget
{
    Q_OBJECT

public:
    explicit auth_reg(QWidget *parent = nullptr);
    ~auth_reg();

private slots:
    void on_pushBut_reg_clicked();

    void on_pushBut_can_clicked();

    void on_pushBut_ok_clicked();

signals:
    void authorization_completed (QString login);

private:
    Ui::auth_reg *ui;

private:
    int flag = 0;
};

#endif // AUTH_REG_H
