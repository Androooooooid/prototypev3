#ifndef MYSETTING_H
#define MYSETTING_H

#include <QSettings>
#include <QVariant>
#include <QString>


class mysetting
{
public:
    mysetting();

    void loadMySet();

    QString getMySetDatabase(), getMySetHostName(), getMySetDatabaseName(), getMySetUserName(), getMySetLogPathGlobal(), getMySetLogPathUser();
    int getMySetMaxLogSize(), getMySetMaxLogFiles(), getMySetMaxLogStorageTime();

private:
    QString  Database, HostName, DatabaseName, UserName, LogPathGlobal, LogPathUser;
    int MaxLogSize, MaxLogFiles, MaxLogStorageTime;

};


#endif // MYSETTING_H
