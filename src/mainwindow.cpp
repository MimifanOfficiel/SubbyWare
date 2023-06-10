#include "includes/mainwindow.hpp"
#include "ui_mainwindow.h"

#include "includes/addpresetdialog.hpp"
#include "includes/modifypresetdialog.hpp"

#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("SubbyWare");
    ui->tabWidget->setTabText(0, "Main");
    ui->tabWidget->setTabText(1, "Configuration");
    ui->tabWidget->setTabText(2, "Presets");
    ui->tabWidget->setTabText(3, "About");

    ui->presets_searchLineEdit->setPlaceholderText("Search for a name... ");
    ui->main_presetComboBox->setPlaceholderText("Preset name");
    ui->main_presetDescriptionTextEdit->setReadOnly(true);

    getPresets("./subbyware.sbw");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::getPresets(QString filePath){
    QFile file(filePath);
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

            preset.setName(obj.value("Name").toString());
            preset.setDescription(obj.value("Description").toString());
            preset.setCategory(obj.value("Category").toString());
            preset.setLocation(obj.value("Location").toString());
            preset.setDomName(obj.value("DomName").toString());
            preset.setDomType(obj.value("DomType").toString());

            presets.push_back(preset);
            ui->presets_listWidget->addItem(preset.getName());
            ui->main_presetComboBox->addItem(preset.getName());
        }
    }

    saved = true;
}

void MainWindow::save(){
    QFile file("./subbyware.sbw");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {return;}
    file.write("[");

    for(int i=0; i<presets.size()-1; i++){
        file.write(presets[i].toJSON().toJson() + ",");
    }
    file.write(presets[presets.size()-1].toJSON().toJson());

    file.write("]");
    saved = true;
}

QString MainWindow::selectFile(bool save){
    QFileDialog fileDialog;
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setNameFilter("Fichiers SubbyWare (*.sbw)"); //filters files by extensions
    fileDialog.setViewMode(QFileDialog::Detail);
    if(save) fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    if(fileDialog.exec()){ return fileDialog.selectedFiles().at(0); } //Returns the path of the first selected file
    return "null";
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
    connect(addDialog, SIGNAL(sendPreset(Preset&)), this, SLOT(addPresetToUI(Preset&)));
    addDialog->show();
    saved = false;
}

void MainWindow::addPresetToUI(Preset &preset){
    presets.push_back(preset);
    ui->presets_listWidget->addItem(preset.getName());
    ui->main_presetComboBox->addItem(preset.getName());
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


void MainWindow::on_presets_listWidget_itemClicked(QListWidgetItem *item) {
    QString presetName = item->text();
    for(Preset &preset : presets){
        if(preset.getName() == presetName){
            ui->presets_infos_presetName->setText(preset.getName());
            ui->presets_infos_presetDomType->setText(preset.getDomType());
            ui->presets_infos_presetDomName->setText(preset.getDomName());
            ui->presets_infos_presetCategoryName->setText(preset.getCategory());
        }
    }
}


void MainWindow::on_main_presetComboBox_currentTextChanged(const QString &arg1) {
    QString presetName = arg1;
    for(Preset &preset : presets){
        if(preset.getName() == presetName){
            ui->main_presetDescriptionTextEdit->setText(preset.getDescription());
        }
    }
}


void MainWindow::on_actionOpen_presets_list_triggered() {
    getPresets(selectFile(false));
}


void MainWindow::on_presets_importButton_clicked() {

}

