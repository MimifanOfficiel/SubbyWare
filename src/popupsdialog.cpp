#include "includes/popupsdialog.hpp"
#include "ui_popupsdialog.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDir>
#include <QFileInfoList>
#include <QScreen>
#include <random>


PopupsDialog::PopupsDialog(QWidget *parent, Preset* _preset) : QDialog(parent), ui(new Ui::PopupsDialog), preset(_preset) {
    ui->setupUi(this);

    setWindowTitle("I obey to " + preset->getDomType() + " " + preset->getDomName());

    QDir dir(preset->getLocation() + "/");
    QFileInfoList files = dir.entryInfoList(QDir::Files);

    QList<QFileInfo> filteredFiles;
    for (const QFileInfo& file : files) {
        if (file.suffix() == "png" || file.suffix() == "jpg" || file.suffix() == "jpeg" || file.suffix() == "gif") {
            filteredFiles.append(file);
        }
    }
    if (filteredFiles.isEmpty()) { close(); }


    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, filteredFiles.size() - 1);
    int randomIndex = dis(gen);

    QString selectedFile = filteredFiles.at(randomIndex).fileName();

    QPixmap image(preset->getLocation() + "/" + selectedFile);
    QPixmap newImg(image.scaled(image.size()*0.5));

    QLabel *imageLabel = new QLabel(this);
    imageLabel->setPixmap(newImg);
    imageLabel->setAlignment(Qt::AlignCenter);

    setFixedSize(sizeHint(newImg));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);

    QPushButton *button = new QPushButton("Yes " + preset->getDomType() + " " + preset->getDomName(), this);
    layout->addWidget(button);
    layout->addStretch();

    setLayout(layout);

    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();

    // Generate random coordinates

    std::uniform_int_distribution<> xDis(0, screenGeometry.width() - width());
    int x = xDis(gen);
    std::uniform_int_distribution<> yDis(0, screenGeometry.height() - height());
    int y = yDis(gen);


    // Move window to these coordinates
    move(x, y);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    connect(button, &QPushButton::clicked, this, &PopupsDialog::accept);
}

QSize PopupsDialog::sizeHint(QPixmap img){
    return QSize(400, img.height());
}

PopupsDialog::~PopupsDialog() {
    delete ui;
}
