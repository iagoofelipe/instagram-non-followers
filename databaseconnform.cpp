#include "databaseconnform.h"
#include "ui_databaseconnform.h"

DatabaseConnForm::DatabaseConnForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseConnForm)
{
    ui->setupUi(this);

    ui->lineHost->setText(cfg.value("db_host", "127.0.0.1").toString());
    ui->lineUser->setText(cfg.value("db_user", "root").toString());
    ui->linePass->setText(cfg.value("db_pass").toString());

    connect(ui->btnBox, SIGNAL(accepted()), this, SIGNAL(continued()));
    connect(ui->btnBox, SIGNAL(rejected()), this, SIGNAL(canceled()));
}

DatabaseConnForm::~DatabaseConnForm()
{
    delete ui;
}

void DatabaseConnForm::on_btnBox_accepted()
{
    cfg.setValue("db_host", ui->lineHost->text());
    cfg.setValue("db_user", ui->lineUser->text());
    cfg.setValue("db_pass", ui->linePass->text());
    emit continued();
}