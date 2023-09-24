#include "ftxui/component/component.hpp"
using namespace ftxui;

Component input_component(std::string* value,
                          std::string placeholder,
                          bool password = false) {
  InputOption input_option;
  input_option.password = password;

  return Input(value, placeholder, input_option);
}