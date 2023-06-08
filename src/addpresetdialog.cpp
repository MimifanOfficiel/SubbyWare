#include "addpresetdialog.hpp"
#include "ui_addpresetdialog.h"

AddPresetDialog::AddPresetDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddPresetDialog) {
    ui->setupUi(this);
    setWindowTitle("New Preset");
}

AddPresetDialog::~AddPresetDialog() {
    delete ui;
}

void AddPresetDialog::on_buttonBox_accepted() {

}


void AddPresetDialog::on_buttonBox_rejected() { close(); }

