#ifndef DATABASEAPI_H
#define DATABASEAPI_H

#include "structs.h"

#include <xdevapi.h>
#include <QString>

class DatabaseAPI
{
public:
    DatabaseAPI();

    QString lastMessageError() const { return error; }
    bool connect(const db_connection_params& params);
    bool updateInstagramUsersIgnore();

private:
    QString error;
    std::unique_ptr<mysqlx::Session> pSess;
};

#endif // DATABASEAPI_H
