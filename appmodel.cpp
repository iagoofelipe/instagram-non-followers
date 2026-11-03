#include "appmodel.h"

#include <QFile>
#include <QRegularExpression>
#include <QCoreApplication>

AppModel::AppModel()
    : db_conn_params(
        cfg.value("db_host").toString(),
        cfg.value("db_port", 33060).toInt(),
        cfg.value("db_user").toString(),
        cfg.value("db_pass").toString()
      )
{
    connect();
}

bool AppModel::connect()
{
    connected = db.connect(db_conn_params);
    if (!connected)
        error = db.lastMessageError();
    return connected;
}

bool AppModel::connect(const db_connection_params& params)
{
    setDatabaseConnectionParams(params);
    return connect();
}

InstagramUsers* AppModel::setUsersFromString(const QString& data)
{
    if (data.isEmpty()) {
        error = "The data cannot be empty";
        return nullptr;
    }

    QRegularExpression regex("<span(?: style=\"color:#aaa\")?>@?([\\s\\S]*?)</span>");
    QRegularExpressionMatchIterator it = regex.globalMatch(data);

    _users.clear();
    users_hash.clear();

    for (int i=0; it.hasNext(); i++) {
        QRegularExpressionMatch match = it.next();

        if (i % 2 == 0)
            _users.emplaceBack(match.captured(1));
        else
            _users[i/2].name = match.captured(1);
    }

    for (auto &u : _users)
        users_hash.insert(u.profile, &u);

    return &_users;
}

InstagramUsers* AppModel::setUsersFromFileName(const QString& fileName)
{
    QFile file(fileName);

    if (fileName.isEmpty() || !fileName.endsWith(".html") || !file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        error = "The input must be an existing HTML file";
        return nullptr;
    }

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);

    QString content = in.readAll();
    file.close();

    return setUsersFromString(content);
}

InstagramUser* AppModel::getInstagramUserByProfile(const QString& profile)
{
    auto it = users_hash.find(profile);
    return it != users_hash.end()? it.value() : nullptr;
}

void AppModel::setDatabaseConnectionParams(const db_connection_params& params)
{
    db_conn_params = params;
    cfg.setValue("db_host", params.host);
    cfg.setValue("db_port", params.port);
    cfg.setValue("db_user", params.user);
    cfg.setValue("db_pass", params.password);
}