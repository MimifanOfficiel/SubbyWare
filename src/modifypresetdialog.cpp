#include "includes/modifypresetdialog.hpp"
#include "ui_modifypresetdialog.h"

#include <QFileDialog>

ModifyPresetDialog::ModifyPresetDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ModifyPresetDialog) {
    ui->setupUi(this);
    setWindowTitle("Modify preset");

    ui->domType_comboBox->addItem("Master");
    ui->domType_comboBox->addItem("Mistress");
    ui->domType_comboBox->addItem("Mommy");
    ui->domType_comboBox->addItem("Daddy");

    ui->categoryComboBox->addItem("Soft");
    ui->categoryComboBox->addItem("Drive filling");
    ui->categoryComboBox->addItem("Censored");
    ui->categoryComboBox->addItem("Gooning");
    ui->categoryComboBox->addItem("Blacked");
    ui->categoryComboBox->addItem("Humiliation");
    ui->categoryComboBox->addItem("Hard");
    ui->categoryComboBox->addItem("Lag");
}

ModifyPresetDialog::~ModifyPresetDialog() { delete ui; }


void ModifyPresetDialog::setOrigins(Preset *_preset){
    preset = _preset;
    ui->presetNameLineEdit->setText(preset->getName());
    ui->domNameLineEdit->setText(preset->getDomName());
    ui->description_textEdit->setText(preset->getDescription());
    ui->categoryComboBox->setCurrentText(preset->getCategory());
    ui->domType_comboBox->setCurrentText(preset->getDomType());
    ui->fullLocationLabel->setText(preset->getLocation());
}


void ModifyPresetDialog::on_buttonBox_accepted() {
    preset->setName(ui->presetNameLineEdit->text());
    preset->setDomName(ui->domNameLineEdit->text());
    preset->setCategory(ui->categoryComboBox->currentText());
    preset->setDescription(ui->description_textEdit->toPlainText());
    preset->setDomType(ui->domType_comboBox->currentText());
    preset->setLocation(ui->fullLocationLabel->text());

    close();
}


void ModifyPresetDialog::on_buttonBox_rejected() { close(); }


void ModifyPresetDialog::on_browseButton_clicked() {
    QString directory = QFileDialog::getExistingDirectory(nullptr, "Choose a folder", "", QFileDialog::ShowDirsOnly);
    if (!directory.isEmpty()) {
        ui->fullLocationLabel->setText(directory);
    }
}

