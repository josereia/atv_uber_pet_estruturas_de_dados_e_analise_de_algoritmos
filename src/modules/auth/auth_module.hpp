#ifndef auth_module
#define auth_module

namespace AuthModule {
void login();
}  // namespace AuthModule

namespace AuthRepository {
bool login(const char* username, const char* password);
bool logout();
}  // namespace AuthRepository

#endif
