#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>

namespace Ui {
class Statistics;
}

class Statistics : public QDialog
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();
    void StartUiStat(QString login);

private slots:

    void on_pushButton_Exit_clicked();

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
