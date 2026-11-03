#ifndef APPMODEL_H
#define APPMODEL_H

#include "databaseapi.h"
#include "structs.h"

#include <QSettings>

class AppModel
{
public:
    AppModel();

    bool connect();
    bool connect(const db_connection_params& params);
    bool isConnected() const { return connected; }
    InstagramUsers* setUsersFromString(const QString& data);
    InstagramUsers* setUsersFromFileName(const QString& fileName);
    QString lastMessageError() const { return error; }
    InstagramUsers* users() { return &_users; }
    InstagramUser* getInstagramUserByProfile(const QString& profile);
    void setDatabaseConnectionParams(const db_connection_params& params);
    const db_connection_params* getDatabaseConnectionParams() { return &db_conn_params; }

private:
    InstagramUsers _users;
    InstagramUsersHash users_hash;
    QString error;
    DatabaseAPI db;
    bool connected;
    QSettings cfg;
    db_connection_params db_conn_params;
};

#endif // APPMODEL_H
