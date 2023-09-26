#include "root_module.hpp"
#include <memory>
#include <string>
#include <vector>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "modules/chauffeur/chauffeur_module.hpp"
#include "modules/clients/clients_module.hpp"
#include "modules/sales/sales_module.hpp"

namespace RootModule {
void screen() {
  auto screen = ftxui::ScreenInteractive::Fullscreen();

  int currentTab = 0;
  std::vector<std::string> tabs{
      "Vendas",
      "Clientes",
      "Motoristas",
  };

  auto tabToggleComponent = ftxui::Toggle(&tabs, &currentTab);
  auto tabContainerComponent = ftxui::Container::Tab(
      {
          SalesModule::page(),
          ClientsModule::page(),
          ChauffeurModule::page(),
      },
      &currentTab);

  auto containerComponent = ftxui::Container::Vertical({
      tabToggleComponent,
      tabContainerComponent,
  });

  auto renderer = Renderer(containerComponent, [&] {
    return ftxui::vbox({
               tabToggleComponent->Render(),
               ftxui::separator(),
               tabContainerComponent->Render(),
           }) |
           ftxui::border;
  });

  screen.Loop(renderer);
}
}  // namespace RootModule