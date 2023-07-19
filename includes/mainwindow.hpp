#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

#include <QVector>
#include <QEvent>
#include <QListWidgetItem>

#include <QCompleter>

#include "includes/preset.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow { Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendPresetToModify(Preset*);

private slots:
    void on_presets_newButton_clicked();
    void on_presets_modifyButton_clicked();
    void on_actionQuit_triggered();

    void closeEvent (QCloseEvent *event);

    void filterName(const QString& filter);

private slots:
    void addPresetToUI(Preset*);

    void on_presets_listWidget_itemClicked(QListWidgetItem *item);
    void on_main_presetComboBox_currentTextChanged(const QString &arg1);
    void on_actionOpen_presets_list_triggered();
    void on_presets_importButton_clicked();

    void on_presets_deleteButton_clicked();

    void on_actionSave_triggered();


    void clearInfos();


    void on_presets_searchLineEdit_textChanged();

    void on_tabWidget_tabBarClicked(int index);


    Preset* getCurrentPreset();

    void run();

private:
    Ui::MainWindow *ui;
    QVector<Preset*> presets;

    QString currentFile = "./subbyware.sbw";
    bool saved = true;

    void getPresets(QString filePath);

    void save();
    void unsavedChanges();

    QString selectFile(bool save);
};

#endif // MAINWINDOW_HPP
