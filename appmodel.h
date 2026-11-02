#ifndef APPMODEL_H
#define APPMODEL_H

#include <QList>
#include <QString>
#include <QHash>

#include "databaseapi.h"

struct InstagramUser{
    QString profile;
    QString name;
    bool famous;

    InstagramUser(QString p="", QString n="", bool f=false)
        : profile(std::move(p)), name(std::move(n)), famous(f) {}
};

typedef QList<InstagramUser> InstagramUsers;

class AppModel
{
public:
    AppModel();

    bool connect();
    bool isConnected() const { return connected; }
    InstagramUsers* setUsersFromString(const QString& data);
    InstagramUsers* setUsersFromFileName(const QString& fileName);
    QString lastMessageError() const { return error; }
    InstagramUsers* users() { return &_users; }
    InstagramUser* getInstagramUserByProfile(const QString& profile);

private:
    InstagramUsers _users;
    QHash<QString, InstagramUser*> users_hash;
    QString error;
    DatabaseAPI db;
    bool connected;
};

#endif // APPMODEL_H
