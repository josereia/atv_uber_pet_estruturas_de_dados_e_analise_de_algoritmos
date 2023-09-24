#include <core/database_driver.cpp>
#include <iostream>
#include "modules/auth/login_module.cpp"

void init() {
  sqlite3* db;
  DatabaseDriver::init(db);
  DatabaseDriver::open("database.db");

  if (!DatabaseDriver::exists("users")) {
    DatabaseDriver::execute(
        "CREATE TABLE users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT NOT NULL,"
        "password TEXT NOT NULL"
        ");");

    DatabaseDriver::execute(
        "INSERT INTO users ("
        "username, password"
        ")"
        "VALUES ('admin', 'admin');");
  }
}

int main(void) {
  init();

  login_module();

  DatabaseDriver::close();
  return EXIT_SUCCESS;
}