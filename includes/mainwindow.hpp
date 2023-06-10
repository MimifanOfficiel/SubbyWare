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

#include "includes/preset.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow { Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_presets_newButton_clicked();
    void on_presets_modifyButton_clicked();
    void on_actionQuit_triggered();

    void closeEvent (QCloseEvent *event);

private slots:
    void addPresetToUI(Preset&);

    void on_presets_listWidget_itemClicked(QListWidgetItem *item);
    void on_main_presetComboBox_currentTextChanged(const QString &arg1);
    void on_actionOpen_presets_list_triggered();
    void on_presets_importButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Preset> presets;
    bool saved = true;

    void getPresets(QString filePath);

    void save();
    void unsavedChanges();

    QString selectFile(bool save);
};

#endif // MAINWINDOW_HPP
