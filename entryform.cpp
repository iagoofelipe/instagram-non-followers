#include "entryform.h"
#include "ui_entryform.h"

#include <QFileDialog>

EntryForm::EntryForm(QWidget *parent, Source source, const QString& data)
    : QWidget(parent)
    , ui(new Ui::EntryForm)
{
    ui->setupUi(this);
    setSource(source, data);
}

EntryForm::~EntryForm()
{
    delete ui;
}

void EntryForm::setText(const QString& text)
{
    ui->textIn->setPlainText(text);
}

QString EntryForm::text() { return ui->textIn->toPlainText(); }

void EntryForm::setFilePath(const QString& path) { ui->lineFile->setText(path); }

QString EntryForm::filePath() { return ui->lineFile->text(); }

void EntryForm::on_btnContinue_clicked() { emit continueRequired(_source, _source == File? filePath() : text()); }

void EntryForm::on_radioFile_clicked() { setSource(File); }

void EntryForm::on_radioText_clicked() { setSource(Text); }

void EntryForm::on_btnBrowse_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select File", "", "HTML Files (*.html)");
    if (!fileName.isEmpty())
        setFilePath(fileName);
}

void EntryForm::setSource(Source s, const QString& data)
{
    _source = s;
    switch (_source) {
    case File:
        ui->frameFile->show();
        ui->frameText->hide();
        ui->radioFile->setChecked(true);
        if (!data.isEmpty()) setFilePath(data);
        break;

    case Text:
        ui->frameText->show();
        ui->frameFile->hide();
        ui->radioText->setChecked(true);
        if (!data.isEmpty()) setText(data);
        break;
    }
}