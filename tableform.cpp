#include "tableform.h"
#include "ui_tableform.h"

#include <QRegularExpression>

TableForm::TableForm(AppModel *model, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TableForm)
    , model(model)
{
    ui->setupUi(this);

    connect(ui->btnContinue, SIGNAL(clicked(bool)), this, SIGNAL(continueRequired()));
    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SIGNAL(backRequired()));

    reloadData();
}

TableForm::~TableForm()
{
    delete ui;
}

void TableForm::reloadData()
{
    ui->table->clearContents();

    const InstagramUsers* users = model->users();
    int row = 0, count = users->size();

    ui->label->setText(QString::number(count) + " result(s) found");
    ui->table->setRowCount(count);
    for (const InstagramUser& ig : *users) {
        ui->table->setItem(row, 0, new QTableWidgetItem(ig.profile));
        ui->table->setItem(row++, 1, new QTableWidgetItem(ig.name));
    }
}