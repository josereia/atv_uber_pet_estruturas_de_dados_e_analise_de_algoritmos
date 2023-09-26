#include "clients_module.hpp"
#include "ftxui/component/component_base.hpp"

namespace ClientsModule {
ftxui::Component page() {
  auto container = ftxui::Container::Vertical({});

  return Renderer(container, [&] {
    return ftxui::center(ftxui::text("Clientes")) | ftxui::border;
  });
}
}  // namespace ClientsModule