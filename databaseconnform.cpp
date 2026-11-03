#include "databaseconnform.h"
#include "ui_databaseconnform.h"

DatabaseConnForm::DatabaseConnForm(AppModel *model, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseConnForm)
    , model(model)
{
    ui->setupUi(this);
    const db_connection_params* params = model->getDatabaseConnectionParams();

    ui->lineHost->setText(params->host);
    ui->lineUser->setText(params->user);
    ui->linePass->setText(params->password);
    ui->spinBox->setValue(params->port);

    connect(ui->btnBox, SIGNAL(rejected()), this, SIGNAL(canceled()));
}

DatabaseConnForm::~DatabaseConnForm()
{
    delete ui;
}

db_connection_params DatabaseConnForm::getDatabaseConnectionParams()
{
    return {
        ui->lineHost->text(),
        ui->spinBox->value(),
        ui->lineUser->text(),
        ui->linePass->text(),
    };
}

void DatabaseConnForm::on_btnBox_accepted()
{
    emit continueRequired(getDatabaseConnectionParams());
}