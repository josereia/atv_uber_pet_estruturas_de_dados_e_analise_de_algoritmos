#include <core/database_driver.hpp>
#include <iostream>
#include <modules/auth/auth_module.hpp>

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
  AuthModule::login();
  DatabaseDriver::close();

  exit(EXIT_SUCCESS);
  return EXIT_SUCCESS;
}