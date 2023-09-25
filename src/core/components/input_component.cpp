#include "components.hpp"
#include "ftxui/component/component.hpp"

namespace Components {
ftxui::Component input(std::string* value,
                       std::string placeholder,
                       bool password) {
  ftxui::InputOption input_option;
  input_option.password = password;

  return ftxui::Input(value, placeholder, input_option);
}
}  // namespace Components