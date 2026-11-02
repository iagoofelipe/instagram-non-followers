#ifndef ENTRYFORM_H
#define ENTRYFORM_H

#include <QWidget>

namespace Ui {
class EntryForm;
}

class EntryForm : public QWidget
{
    Q_OBJECT

public:
    enum Source {
        File, Text
    };

    explicit EntryForm(QWidget *parent = nullptr, Source source=File, const QString& data=QString());
    ~EntryForm();

    void setText(const QString& text);
    QString text();

    void setFilePath(const QString& path);
    QString filePath();

    void setSource(Source s, const QString& data=QString());
    Source source() const { return _source; }

signals:
    void continueRequired(EntryForm::Source, QString);

protected slots:
    void on_btnContinue_clicked();
    void on_radioFile_clicked();
    void on_radioText_clicked();
    void on_btnBrowse_clicked();

private:
    Ui::EntryForm *ui;
    Source _source;
};

#endif // ENTRYFORM_H
