#include "includes/mainwindow.hpp"
#include "ui_mainwindow.h"

#include "includes/addpresetdialog.hpp"
#include "includes/modifypresetdialog.hpp"

#include <QMessageBox>

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

MainWindow::~MainWindow() { delete ui; }

void MainWindow::getPresets(){
    QFile file("./subbyware.sbw");
    if (!file.open(QIODevice::ReadOnly)) { qWarning("Failed to open file"); return; }

    QByteArray data = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

    if (jsonDoc.isNull()) { qWarning("Failed to create JSON document"); return; }
    if (!jsonDoc.isArray()) { qWarning("JSON document is not an array !"); return; }

    QJsonArray jsonArray = jsonDoc.array();
    for (int i = 0; i < jsonArray.size(); ++i) {
        QJsonValue value = jsonArray.at(i);
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            Preset preset;

            preset.setName(obj.value("name").toString());
            preset.setDescription(obj.value("description").toString());
            preset.setLocation(obj.value("dirLocation").toString());
            preset.setDomName(obj.value("domName").toString());
            preset.setDomType(obj.value("domType").toString());

            presets.push_back(preset);
        }
    }
    saved = true;
}

void MainWindow::save(){

}

void MainWindow::unsavedChanges(){
    QMessageBox msgBox; //Creation of message box

    //Setting message box text
    msgBox.setText("Some changes has not been saved.");
    msgBox.setInformativeText("Do you want to save?");

    //Setting message box options and default option
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);

    //Check what have been done
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        // Save was clicked
        save(); //We save to the current file
        QApplication::quit();   //We close the application
        break;
    case QMessageBox::Discard:
        // Don't Save was clicked
        QApplication::quit(); //Closing application without saving
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        return; //We do nothing but close the dialog
        break;
    default:
        // should never be reached
        break;
    }
}

void MainWindow::on_presets_newButton_clicked() {
    AddPresetDialog *addDialog = new AddPresetDialog();

    addDialog->show();
    saved = false;
}


void MainWindow::on_presets_modifyButton_clicked() {
    ModifyPresetDialog *modifyDialog = new ModifyPresetDialog();

    modifyDialog->show();
    saved = false;
}

void MainWindow::closeEvent (QCloseEvent *event) {
    if(saved) QApplication::quit();
    else unsavedChanges();
}

void MainWindow::on_actionQuit_triggered() {
    if(saved) QApplication::quit();
    else unsavedChanges();
}

