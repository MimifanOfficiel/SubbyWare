#ifndef ADDPRESETDIALOG_H
#define ADDPRESETDIALOG_H

#include <QDialog>

#include "preset.hpp"

namespace Ui { class AddPresetDialog; }

class AddPresetDialog : public QDialog { Q_OBJECT

public:
    explicit AddPresetDialog(QWidget *parent = nullptr);
    ~AddPresetDialog();

signals:
    void sendPreset(Preset&);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_presetNameLineEdit_textEdited(const QString &arg1);
    void on_description_textEdit_textChanged();

    void checkForm();

private:
    Ui::AddPresetDialog *ui;
};

#endif // ADDPRESETDIALOG_H
