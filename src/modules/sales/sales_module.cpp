#include "sales_module.hpp"
#include "ftxui/component/component_base.hpp"

namespace SalesModule {
ftxui::Component page() {
  auto container = ftxui::Container::Vertical({});

  return Renderer(container, [&] {
    return ftxui::center(ftxui::text("Vendas")) | ftxui::border;
  });
}
}