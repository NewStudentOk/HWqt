#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QNetworkAccessManager>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager networkManager;
    qDebug() << "Network access manager created";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("testdb");

    if(!db.open())
    {
        qDebug() << "Error opening database: " << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully";
    }

    return a.exec();
}
