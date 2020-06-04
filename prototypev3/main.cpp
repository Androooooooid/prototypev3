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
    qInstallMessageHandler(messageHandler);
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}



// Реализация обработчика
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QDir dir(myset.getMySetLogPathUser());
    QFileInfoList st1 = dir.entryInfoList(QDir::NoFilter, QDir::Time);

    if (st1.length()==2)
    {
        m_logFile.reset(new QFile(myset.getMySetLogPathUser()+(QCoreApplication::applicationName())+"_"+(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh:mm:ss.zzz")+".csv")));
        m_logFile.data()->open(QFile::Append | QFile::Text);
        m_logFile.data()->close();
        st1 = dir.entryInfoList(QDir::NoFilter, QDir::Time);
    }

    //qDebug()<<"Начинаем искать последний изменённый лог файл по дате(обладает свойством не пустого baseName) сортированно по времени"<<endl;
    int ind=0;//Индекс нужного нам лога
    for (int i=0;st1[i].baseName()=="" ; i++)
    {
        ind=i+1;//Изменяем пока не найдём нужный лог
    }

    QFileInfo f2=st1[ind];//Начинаем работать с нужным нам логом
    QFileInfo fileinfo(f2.absoluteFilePath()); //указываем абсолютный путь к логу к последнему созданому
    qint64 size = fileinfo.size();

    //qDebug()<<myset.getMySetMaxLogSize()<<size;
    if (myset.getMySetMaxLogSize()<size)
    {
        // Устанавливаем файл логирования
        m_logFile.reset(new QFile(myset.getMySetLogPathUser()+(QCoreApplication::applicationName())+"_"+(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh:mm:ss.zzz")+".csv")));
        // Открываем файл логирования
        m_logFile.data()->open(QFile::Append | QFile::Text);
        // Устанавливаем обработчик

    }
    else
    {
        m_logFile.reset(new QFile(f2.absoluteFilePath()));
        // Открываем файл логирования
        m_logFile.data()->open(QFile::Append | QFile::Text);
        // Устанавливаем обработчик

    }

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


