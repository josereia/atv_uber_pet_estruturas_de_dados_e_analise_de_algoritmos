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
  using namespace std;

  auto screen = ftxui::ScreenInteractive::Fullscreen();

  string username;
  string password;

  auto usernameInputComponent =
      Components::input(&username, "Digite seu nome de usuário", false);
  auto passwordInputComponent =
      Components::input(&password, "Digite sua senha", true);

  auto formComponent = ftxui::Container::Vertical({
      usernameInputComponent,
      passwordInputComponent,
  });

  auto renderer = Renderer(formComponent, [&] {
    if (AuthRepository::login(username.c_str(), password.c_str())) {
      screen.ExitLoopClosure()();
      RootModule::screen();
    }

    return ftxui::vbox({
               ftxui::hbox(ftxui::text("Olá! Bem-vindo(a) "),
                           ftxui::text(username) | ftxui::bold),
               ftxui::separator(),
               hbox(ftxui::text("Nome de usuário: "),
                    usernameInputComponent->Render()),
               ftxui::hbox(ftxui::text("Senha: "),
                           passwordInputComponent->Render()),
           }) |
           ftxui::border;
  });

  screen.Loop(renderer);
}
}  // namespace AuthModule