#include <stdio.h>
#include <string>

#include "components/input_component.cpp"
#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/util/ref.hpp"

void login_module() {
  // using namespace ftxui;
  auto screen = ScreenInteractive::TerminalOutput();

  std::string username;
  std::string password;

  auto usernameInputComponent =
      input_component(&username, "Digite seu nome de usuário");
  auto passwordInputComponent =
      input_component(&password, "Digite sua senha", true);

  auto formComponent = Container::Vertical({
      usernameInputComponent,
      passwordInputComponent,
  });

  auto renderer = Renderer(formComponent, [&] {
    if (username.compare("admin") == 0 && password.compare("admin") == 0) {
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