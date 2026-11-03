#ifndef DATABASECONNFORM_H
#define DATABASECONNFORM_H

#include "appmodel.h"

#include <QWidget>
#include <QSettings>

namespace Ui {
class DatabaseConnForm;
}

class DatabaseConnForm : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseConnForm(AppModel *model, QWidget *parent = nullptr);
    ~DatabaseConnForm();

    db_connection_params getDatabaseConnectionParams();

private slots:
    void on_btnBox_accepted();

signals:
    void continueRequired(db_connection_params);
    void canceled();

private:
    Ui::DatabaseConnForm *ui;
    AppModel *model;
};

#endif // DATABASECONNFORM_H
