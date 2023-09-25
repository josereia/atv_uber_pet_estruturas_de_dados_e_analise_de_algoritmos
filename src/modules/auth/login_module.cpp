#include <stdio.h>
#include <string>
#include "auth_module.hpp"

#include "core/components/components.hpp"
#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/util/ref.hpp"
#include "modules/root/root_module.hpp"

namespace AuthModule {
void login() {
  using namespace ftxui;
  using namespace std;

  auto screen = ftxui::ScreenInteractive::TerminalOutput();

  string username;
  string password;

  auto usernameInputComponent =
      Components::input(&username, "Digite seu nome de usuário", false);
  auto passwordInputComponent =
      Components::input(&password, "Digite sua senha", true);

  auto formComponent = Container::Vertical({
      usernameInputComponent,
      passwordInputComponent,
  });

  auto renderer = Renderer(formComponent, [&] {
    if (AuthRepository::login(username.c_str(), password.c_str())) {
      screen.ExitLoopClosure()();
    }

    return vbox({
               hbox(text("Olá! Bem-vindo(a) "), text(username) | bold),
               separator(),
               hbox(text("Nome de usuário: "),
                    usernameInputComponent->Render()),
               hbox(text("Senha: "), passwordInputComponent->Render()),
           }) |
           border;
  });

  screen.Loop(renderer);
}
}  // namespace AuthModule