#ifndef components
#define components

#include <ftxui/component/component.hpp>

namespace Components {
ftxui::Component input(std::string* value,
                       std::string placeholder,
                       bool password);
}

#endif