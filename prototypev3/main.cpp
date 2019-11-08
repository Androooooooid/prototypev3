#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QScopedPointer>
#include <QTextStream>
#include <QDateTime>
#include "loggingcategories.h"

/*
FEDERAL RESEARCH-AND-PRODUCTION CENTRE
JOIN-STOCK COMPANY
"RESEARCH-AND-PRODUCTION ASSOCIATION "MARS"
(FRPC JSC "RPA "MARS")
*/

QScopedPointer<QFile>   m_logFile;
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[])
{
    /* Для адекватной регистрации приложения в операционной
    * необходимо установить название организации, домен организации,
    * а также название приложения.
    * */
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QCoreApplication::setApplicationVersion("3.0");

    QApplication a(argc, argv);

    // Устанавливаем файл логирования
    m_logFile.reset(new QFile("./logFile.csv"));
    // Открываем файл логирования
    m_logFile.data()->open(QFile::Append | QFile::Text);
    // Устанавливаем обработчик
    qInstallMessageHandler(messageHandler);

    MainWindow w;
    w.show();

    return a.exec();
}

// Реализация обработчика
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // Открываем поток записи в файл
    QTextStream out(m_logFile.data());
    // Записываем дату записи
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz "",");
    // По типу определяем, к какому уровню относится сообщение
    switch (type)
    {
    case QtInfoMsg:     out << "INF " ","; break;
    case QtDebugMsg:    out << "DBG " ","; break;
    case QtWarningMsg:  out << "WRN " ","; break;
    case QtCriticalMsg: out << "CRT " ","; break;
    case QtFatalMsg:    out << "FTL " ","; break;
    }
    // Записываем в вывод категорию сообщения и само сообщение
    out << context.category << ", "
        << msg << endl;
    out.flush();    // Очищаем буферизированные данные
}

