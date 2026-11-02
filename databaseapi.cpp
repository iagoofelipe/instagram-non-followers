#include "databaseapi.h"

DatabaseAPI::DatabaseAPI() {}

bool DatabaseAPI::connect()
{
    try {
        mysqlx::Session sess(
            cfg.value("db_host", "127.0.0.1").toString().toStdString(),
            33060,
            cfg.value("db_user", "root").toString().toStdString(),
            cfg.value("db_pass").toString().toStdString()
        );
    } catch (mysqlx::Error &err) {
        error = err.what();
        return false;
    }

    return true;
}