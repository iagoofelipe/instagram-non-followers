#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaseconnform.h"

#include <QTextDocument>
#include <QTextCursor>
#include <QRegularExpression>
#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , entryForm(nullptr)
    , tableForm(nullptr)
    , entryFormSource(EntryForm::File)
{
    ui->setupUi(this);
    setWindowTitle("Instagram non-followers");
    connect(ui->actionDbConn, &QAction::triggered, this, &MainWindow::setDatabaseConnForm);

    if (!model.isConnected()) {
        setErrorForm();
        return;
    }

    setEntryForm();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_databaseConnForm_continueRequired(db_connection_params params)
{
    model.connect(params)? setEntryForm() : setErrorForm();
}

void MainWindow::on_databaseConnForm_canceled()
{
    if (tableForm)
        setTableForm();
    else if (model.isConnected() || model.connect())
        setEntryForm();
    else
        setErrorForm();
}

void MainWindow::on_entryForm_continueRequired(EntryForm::Source source, QString data)
{
    QList<InstagramUser> *users;

    switch (source) {
    case EntryForm::File:
        users = model.setUsersFromFileName(data);
        break;

    case EntryForm::Text:
        users = model.setUsersFromString(data);
        break;
    }

    if (!users) {
        QMessageBox::critical(this, "Validation Error", model.lastMessageError());
        return;
    }

    entryFormSource = source;
    entryFormContent = data;

    setTableForm();
}

void MainWindow::setDatabaseConnForm()
{
    DatabaseConnForm *view = new DatabaseConnForm(&model);
    connect(view, &DatabaseConnForm::continueRequired, this, &MainWindow::on_databaseConnForm_continueRequired);
    connect(view, &DatabaseConnForm::canceled, this, &MainWindow::on_databaseConnForm_canceled);
    setCentralWidget(view);
}

void MainWindow::setEntryForm()
{
    tableForm = nullptr;
    entryForm = new EntryForm(nullptr, entryFormSource, entryFormContent);

    setCentralWidget(entryForm);
    connect(entryForm, &EntryForm::continueRequired, this, &MainWindow::on_entryForm_continueRequired);
}

void MainWindow::setTableForm()
{
    entryForm = nullptr;
    tableForm = new TableForm(&model);

    setCentralWidget(tableForm);
    connect(tableForm, &TableForm::backRequired, this, &MainWindow::setEntryForm);
}

void MainWindow::setErrorForm() { setErrorForm(model.lastMessageError()); }

void MainWindow::setErrorForm(const QString& msg)
{
    entryForm = nullptr;
    tableForm = nullptr;
    QLabel *label = new QLabel(msg);
    label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    setCentralWidget(label);
}
