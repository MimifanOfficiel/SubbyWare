#include "includes/mainwindow.hpp"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QFileInfo>
#include <QDir>

void downloadImage(QUrl url){
    // Création du gestionnaire de réseau
    QNetworkAccessManager manager;

    // Effectuer la requête HTTP pour télécharger le fichier
    QNetworkReply* reply = manager.get(QNetworkRequest(url));

    // Attendre la fin du téléchargement
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Vérifier si la requête a réussi
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error downloading :" << reply->errorString();
        reply->deleteLater();
        return;
    }

    QString fileName = QFileInfo(url.path()).fileName();

    QFile file("./ressources/imgs/" + fileName);
    if(file.open(QIODevice::WriteOnly)) {
        file.write(reply->readAll());
        file.close();
    } else {
        qDebug() << "Error on moving file";
    }

    file.write(reply->readAll());

    file.close();
    reply->deleteLater();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QTranslator translator;
    if (translator.load(":/i18n/SubbyWare_" + QLocale::system().name())) { a.installTranslator(&translator); }

    QDir ressources("./ressources");
    if(!ressources.exists()){
        ressources.mkpath("imgs");
        downloadImage(QUrl("https://i.pinimg.com/736x/c1/28/39/c128399e3d3efee7bde238dcd0a12864.jpg"));
        downloadImage(QUrl("https://static1.e621.net/data/sample/f2/2b/f22b3cb315b1f5ea47c4e7ea7d159373.jpg"));
        downloadImage(QUrl("https://static1.e621.net/data/16/e8/16e8b2a557e111f4cc62671f2eeea4bb.png"));
        downloadImage(QUrl("https://s18.erome.com/921/uznrlaYR/D1mx8xJN.jpeg?v=1657112116"));
        downloadImage(QUrl("https://pornwithtext.com/content/2022/12/hot-caption-137_001.gif"));
    }

    MainWindow w;
    w.show();
    return a.exec();
}


