#include "mysetting.h"
#include "QSettings"
#include <QApplication>
#include <QDebug>
mysetting::mysetting()
{

}
void mysetting::loadMySet()
{
    QSettings settings("mysetting.conf", QSettings::IniFormat);
    settings.beginGroup("Database");
    Database = settings.value("addDatabase" "").toString();
    HostName = settings.value("setHostName", "").toString();
    DatabaseName = settings.value("setDatabaseName", "").toString();
    UserName = settings.value("setUserName", "").toString();
    settings.endGroup();
    settings.beginGroup("Logger");
    LogPathGlobal = settings.value("logPathGlobal" "").toString();
    LogPathUser = settings.value("logPathUser" "").toString();
    MaxLogSize = settings.value("maxLogSize" "").toInt();
    MaxLogFiles = settings.value("maxLogFiles" "").toInt();
    MaxLogStorageTime = settings.value("maxLogStorageTime" "").toInt();
    settings.endGroup();

}

QString mysetting::getMySetDatabase()
{
    return Database;
}

QString mysetting::getMySetHostName()
{
    return HostName;
}

QString mysetting::getMySetDatabaseName()
{
    return DatabaseName;
}

QString mysetting::getMySetUserName()
{
    return UserName;
}

QString mysetting::getMySetLogPathGlobal()
{
    return LogPathGlobal;
}
QString mysetting::getMySetLogPathUser()
{
    return LogPathUser;
}
int mysetting::getMySetMaxLogSize()
{
    return MaxLogSize;
}

int mysetting::getMySetMaxLogFiles()
{
    return MaxLogFiles;
}

int mysetting::getMySetMaxLogStorageTime()
{
    return MaxLogStorageTime;
}
