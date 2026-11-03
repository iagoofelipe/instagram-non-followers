#include "databaseapi.h"

DatabaseAPI::DatabaseAPI() {}

bool DatabaseAPI::connect(const db_connection_params& params)
{
    try {
        pSess = std::make_unique<mysqlx::Session>(
            params.host.toStdString(),
            params.port,
            params.user.toStdString(),
            params.password.toStdString()
        );
    } catch (mysqlx::Error &err) {
        error = err.what();
        return false;
    }

    return true;
}

bool DatabaseAPI::updateInstagramUsersIgnore()
{
    if (!pSess) {
        error = "no session found";
        return false;
    }



    try {
        mysqlx::Schema db = pSess->getSchema("instagram_non_followers");
        mysqlx::Table table = db.getTable("user");
        // table.select("profile")
        //     .where("profile IN (:names")
        //     .bind("names", );

    } catch (mysqlx::Error &err) {
        error = err.what();
        return false;
    }

    return true;
}