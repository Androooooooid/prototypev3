#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QScopedPointer>
#include <QTextStream>
#include <QDateTime>
#include "loggingcategories.h"
#include "mysetting.h"
#include <stdio.h>
#include "QFileInfo"
#include <QTranslator>

/*
FEDERAL RESEARCH-AND-PRODUCTION CENTRE
JOIN-STOCK COMPANY
"RESEARCH-AND-PRODUCTION ASSOCIATION "MARS"
(FRPC JSC "RPA "MARS")
*/

mysetting myset;



QScopedPointer<QFile>   m_logFile;
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[])
{
    myset.loadMySet();
    myset.getMySetMaxLogSize();
    myset.getMySetLogPathGlobal();
    myset.getMySetMaxLogFiles();
    /* Для адекватной регистрации приложения в операционной
    * необходимо установить название организации, домен организации,
    * а также название приложения.
    * */
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QCoreApplication::setApplicationVersion("3.0");

    QDir dir(myset.getMySetLogPathUser());
    QFileInfoList st1 = dir.entryInfoList(QDir::NoFilter, QDir::Time);
//  qDebug()<<st1.size()<<endl<<st1.length();
    if (st1.length()==2)
    {
        QFile file(myset.getMySetLogPathUser()+(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh:mm:ss.zzz")+".csv"));
    }
    int ind;
    for (int i=0;st1[i].baseName()=="" ; i++)
    {
        qDebug()<<st1[i].baseName();
        ind=i+1;
    }
    QFileInfo f2=st1[2];
//    if (!QFileInfo fileinfo(f2.absoluteFilePath()));
//    {
//        new QFile(myset.getMySetLogPathUser()+(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh:mm:ss.zzz")+".csv"));
//    }
    QFileInfo fileinfo(f2.absoluteFilePath()); //указываем абсолютный путь к логу к последнему созданому
    qint64 size = fileinfo.size();
    qDebug()<<size;
    QApplication a(argc, argv);

        qDebug()<<myset.getMySetMaxLogSize()<<size;
    if (myset.getMySetMaxLogSize()<size)
    {
        // Устанавливаем файл логирования
        m_logFile.reset(new QFile(myset.getMySetLogPathUser()+(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh:mm:ss.zzz")+".csv")));
        // Открываем файл логирования
        m_logFile.data()->open(QFile::Append | QFile::Text);
        // Устанавливаем обработчик
        qInstallMessageHandler(messageHandler);
    }
    else
    {
        m_logFile.reset(new QFile(f2.absoluteFilePath()));
        // Открываем файл логирования
        m_logFile.data()->open(QFile::Append | QFile::Text);
        // Устанавливаем обработчик
        qInstallMessageHandler(messageHandler);

    }
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
    out << context.category << ","
        << msg << endl;
    out.flush();    // Очищаем буферизированные данные
}

