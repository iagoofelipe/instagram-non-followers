#ifndef DATABASECONNFORM_H
#define DATABASECONNFORM_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class DatabaseConnForm;
}

class DatabaseConnForm : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseConnForm(QWidget *parent = nullptr);
    ~DatabaseConnForm();

private slots:
    void on_btnBox_accepted();

signals:
    void continued();
    void canceled();

private:
    Ui::DatabaseConnForm *ui;
    QSettings cfg;
};

#endif // DATABASECONNFORM_H
