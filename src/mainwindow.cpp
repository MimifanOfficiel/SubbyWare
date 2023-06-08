#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "addpresetdialog.hpp"
#include "modifypresetdialog.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("SubbyWare");
    ui->tabWidget->setTabText(0, "Main");
    ui->tabWidget->setTabText(1, "Configuration");
    ui->tabWidget->setTabText(2, "Presets");
    ui->tabWidget->setTabText(3, "About");

    ui->presets_searchLineEdit->setPlaceholderText("Search for a name... ");
    ui->main_presetComboBox->setPlaceholderText("Preset name");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_presets_newButton_clicked() {
    AddPresetDialog *addDialog = new AddPresetDialog();

    addDialog->show();
}


void MainWindow::on_presets_modifyButton_clicked() {
    ModifyPresetDialog *modifyDialog = new ModifyPresetDialog();

    modifyDialog->show();

}

