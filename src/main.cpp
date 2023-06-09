#include "includes/mainwindow.hpp"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QTranslator translator;
    if (translator.load(":/i18n/brandon-izoulet-sae-2-01_" + QLocale::system().name())) { a.installTranslator(&translator); }

    MainWindow w;
    w.show();
    return a.exec();
}
