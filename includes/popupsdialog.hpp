#ifndef POPUPSDIALOG_HPP
#define POPUPSDIALOG_HPP

#include <QDialog>

#include "preset.hpp"

namespace Ui {
class PopupsDialog;
}

class PopupsDialog : public QDialog {
    Q_OBJECT

public:
    explicit PopupsDialog(QWidget *parent = nullptr, Preset *_preset = new Preset());
    ~PopupsDialog();

    QSize sizeHint(QPixmap img);

private:
    Ui::PopupsDialog *ui;
    Preset *preset;
};

#endif // POPUPSDIALOG_HPP
