#ifndef ADDPRESETDIALOG_H
#define ADDPRESETDIALOG_H

#include <QDialog>

namespace Ui { class AddPresetDialog; }

class AddPresetDialog : public QDialog { Q_OBJECT

public:
    explicit AddPresetDialog(QWidget *parent = nullptr);
    ~AddPresetDialog();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddPresetDialog *ui;
};

#endif // ADDPRESETDIALOG_H
