#ifndef TABLEFORM_H
#define TABLEFORM_H

#include <QWidget>

#include "appmodel.h"

namespace Ui {
class TableForm;
}



class TableForm : public QWidget
{
    Q_OBJECT

public:
    explicit TableForm(AppModel *model, QWidget *parent = nullptr);
    ~TableForm();

    void reloadData();

signals:
    void continueRequired();
    void backRequired();

private:
    Ui::TableForm *ui;
    AppModel *model;
};

#endif // TABLEFORM_H
