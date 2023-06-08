#include "modifypresetdialog.hpp"
#include "ui_modifypresetdialog.h"

ModifyPresetDialog::ModifyPresetDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ModifyPresetDialog) {
    ui->setupUi(this);
    setWindowTitle("Modify preset");
}

ModifyPresetDialog::~ModifyPresetDialog() { delete ui; }

void ModifyPresetDialog::on_buttonBox_accepted() {

}


void ModifyPresetDialog::on_buttonBox_rejected() { close(); }

