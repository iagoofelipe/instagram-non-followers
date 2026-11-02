#ifndef DATABASEAPI_H
#define DATABASEAPI_H

#include <xdevapi.h>
#include <QString>
#include <QSettings>

class DatabaseAPI
{
public:
    DatabaseAPI();

    QString lastMessageError() const { return error; }
    bool connect();

private:
    QString error;
    QSettings cfg;
};

#endif // DATABASEAPI_H
