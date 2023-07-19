#include "includes/addpresetdialog.hpp"
#include "ui_addpresetdialog.h"

#include <QFileDialog>

#include "includes/presetConfigurations.hpp"

AddPresetDialog::~AddPresetDialog() { delete ui; }
AddPresetDialog::AddPresetDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddPresetDialog) {
    ui->setupUi(this);
    setWindowTitle("New Preset");

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

    ui->fullLocationLabel->setText("./ressources");

    ui->buttonBox->setEnabled(false);
}

void AddPresetDialog::on_buttonBox_rejected() { close(); }
void AddPresetDialog::on_buttonBox_accepted() {
    Preset *preset = new Preset();
    preset->setName(ui->presetNameLineEdit->text());
    preset->setDescription(ui->description_textEdit->toPlainText());
    preset->setCategory(ui->categoryComboBox->currentText());
    preset->setDomType(ui->domType_comboBox->currentText());
    preset->setDomName(ui->domNameLineEdit->text());
    preset->setLocation(ui->fullLocationLabel->text());

    PresetConfigurations *config = new PresetConfigurations();
    config->setPopupInterval(2000);

    preset->setConfig(config);

    emit sendPreset(preset);
}

void AddPresetDialog::checkForm(){
    if(!ui->presetNameLineEdit->text().isEmpty() && !ui->description_textEdit->toPlainText().isEmpty()){
        ui->buttonBox->setEnabled(true);
    } else {
        ui->buttonBox->setEnabled(false);
    }
}

void AddPresetDialog::on_presetNameLineEdit_textEdited() { checkForm(); }
void AddPresetDialog::on_description_textEdit_textChanged() { checkForm(); }


void AddPresetDialog::on_browseButton_clicked() {
    QString directory = QFileDialog::getExistingDirectory(nullptr, "Choose a folder", "", QFileDialog::ShowDirsOnly);
    if (!directory.isEmpty()) {
        ui->fullLocationLabel->setText(directory);
    }
}

