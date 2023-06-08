#ifndef MODIFYPRESETDIALOG_HPP
#define MODIFYPRESETDIALOG_HPP

#include <QDialog>

namespace Ui {
class ModifyPresetDialog;
}

class ModifyPresetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyPresetDialog(QWidget *parent = nullptr);
    ~ModifyPresetDialog();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::ModifyPresetDialog *ui;
};

#endif // MODIFYPRESETDIALOG_HPP
