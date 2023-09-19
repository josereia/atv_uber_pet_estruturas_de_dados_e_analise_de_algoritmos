#include <stdio.h>
#include <string>

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp"  // for Ref

std::string user = "admin";
char password[9] = "admin123";

void login_module() {
  using namespace ftxui;
  auto screen = ScreenInteractive::TerminalOutput();

  std::string title;
  std::string user_input;
  char password_input[9];

  InputOption user_input_option;
  Component user_input_component =
      Input(&user_input, "Digite seu usuário", user_input_option);

  InputOption password_option;
  password_option.password = true;
  Component password_input_component =
      Input(password_input, "Digite sua senha", password_option);

  password_option.on_enter = [&] {
    title = "Bem-vindo(a), " + user_input + "!";
  };

  auto component = Container::Vertical({
      user_input_component,
      password_input_component,
  });

  auto renderer = Renderer(component, [&] {
    return vbox({
               text("Bem-vindo(a)! Faça login."),
               separator(),
               hbox(text("Usuário: "), user_input_component->Render()),
               hbox(text("Senha: "), password_input_component->Render()),
           }) |
           border;
  });

  screen.Loop(renderer);
}