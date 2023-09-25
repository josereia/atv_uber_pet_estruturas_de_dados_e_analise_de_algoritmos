#include <core/database_driver.hpp>
#include <iostream>
#include "auth_module.hpp"

namespace AuthRepository {
bool login(const char* username, const char* password) {
  std::string sql = "SELECT id FROM users WHERE username ='" +
                    std::string(username) + "' AND password ='" +
                    std::string(password) + "'";

  auto [_, stmt] = DatabaseDriver::prepare(sql.c_str());
  int rc = DatabaseDriver::step(stmt);

  return rc == SQLITE_ROW;
};

bool logout() {
  int rc = DatabaseDriver::close();
  return rc == SQLITE_OK;
};
}  // namespace AuthRepository