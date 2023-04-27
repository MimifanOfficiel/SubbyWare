
#include "mainwindow.hpp"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    setFixedSize(size());
    setWindowTitle("SubbyWare");
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Main");
    ui->tabWidget->setTabText(1, "Configuration");
    ui->tabWidget->setTabText(2, "Presets");
    ui->tabWidget->setTabText(3, "About");
}

MainWindow::~MainWindow() {
    delete ui;
}


