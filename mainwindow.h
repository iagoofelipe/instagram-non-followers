#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "appmodel.h"
#include "entryform.h"
#include "tableform.h"

#include <QMainWindow>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AppModel model;
    EntryForm *entryForm;
    TableForm *tableForm;
    EntryForm::Source entryFormSource;
    QString entryFormContent;

    void on_databaseConnForm_continueRequired(db_connection_params params);
    void on_databaseConnForm_canceled();
    void on_entryForm_continueRequired(EntryForm::Source source, QString data);

    void setDatabaseConnForm();
    void setEntryForm();
    void setTableForm();
    void setErrorForm();
    void setErrorForm(const QString& msg);
};

#endif // MAINWINDOW_H
