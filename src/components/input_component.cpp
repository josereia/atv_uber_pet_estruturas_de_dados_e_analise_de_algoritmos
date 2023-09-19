#include "ftxui/component/component.hpp"
using namespace ftxui;

Component input_component(
    std::string& value,
    std::string placeholder,
    bool password = false,
    std::function<void()> on_enter = []() {}) {
  InputOption input_option;

  input_option.password = password;
  input_option.on_enter = on_enter;

  return Input(value, placeholder);
}