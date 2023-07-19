#ifndef MODIFYPRESETDIALOG_HPP
#define MODIFYPRESETDIALOG_HPP

#include <QDialog>
#include "preset.hpp"

namespace Ui { class ModifyPresetDialog; }

class ModifyPresetDialog : public QDialog { Q_OBJECT

public:
    explicit ModifyPresetDialog(QWidget *parent = nullptr);
    ~ModifyPresetDialog();

signals:
    void sendModifiedPreset(QString, Preset*);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

    void setOrigins(Preset*);

    void on_browseButton_clicked();

private:
    Ui::ModifyPresetDialog *ui;
    Preset *preset;
};

#endif // MODIFYPRESETDIALOG_HPP
