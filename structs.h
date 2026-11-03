#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QList>
#include <QHash>

struct db_connection_params {
    QString host;
    int port;
    QString user;
    QString password;

    db_connection_params(QString h="", int po=33060, QString u="", QString ps="")
        : host(std::move(h)), port(po), user(std::move(u)), password(std::move(ps)) {}
};

struct InstagramUser{
    QString profile;
    QString name;
    bool ignore;

    InstagramUser(QString p="", QString n="", bool i=false)
        : profile(std::move(p)), name(std::move(n)), ignore(i) {}
};

typedef QList<InstagramUser> InstagramUsers;

typedef QHash<QString, InstagramUser*> InstagramUsersHash;

#endif // STRUCTS_H
