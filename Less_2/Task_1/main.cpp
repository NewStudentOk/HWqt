#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QNetworkAccessManager>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager networkManager;
    qDebug() << "Network access manager created";

    // Пример когда все работает

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("testdb");

    //Пример когда не все работает

//    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
//    db.setHostName("127.0.0.1");
//    db.setDatabaseName("testdb");
//    db.setPort(5432);
//    db.setUserName("user");
//    db.setPassword("12345678");

    if(!db.open())
    {
        qDebug() << "Error opening database: " << db.lastError().text();
        return a.closingDown(); //закрой если все плохо
    } else {
        qDebug() << "Database opened successfully";
    }

    return a.exec();
}
