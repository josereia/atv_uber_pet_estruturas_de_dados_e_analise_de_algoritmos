#include "root_module.hpp"
#include <memory>
#include <string>
#include <vector>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

namespace RootModule {
void root() {
  std::vector<std::string> tab_values{
      "tab_1",
      "tab_2",
      "tab_3",
  };
  int tab_selected = 0;
  auto tab_toggle = ftxui::Toggle(&tab_values, &tab_selected);

  std::vector<std::string> tab_1_entries{
      "Forest",
      "Water",
      "I don't know",
  };
  int tab_1_selected = 0;

  std::vector<std::string> tab_2_entries{
      "Hello",
      "Hi",
      "Hay",
  };
  int tab_2_selected = 0;

  std::vector<std::string> tab_3_entries{
      "Table",
      "Nothing",
      "Is",
      "Empty",
  };
  int tab_3_selected = 0;
  auto tab_container = ftxui::Container::Tab(
      {
          ftxui::Radiobox(&tab_1_entries, &tab_1_selected),
          ftxui::Radiobox(&tab_2_entries, &tab_2_selected),
          ftxui::Radiobox(&tab_3_entries, &tab_3_selected),
      },
      &tab_selected);

  auto container = ftxui::Container::Vertical({
      tab_toggle,
      tab_container,
  });

  auto renderer = Renderer(container, [&] {
    return ftxui::vbox({
               tab_toggle->Render(),
               ftxui::separator(),
               tab_container->Render(),
           }) |
           ftxui::border;
  });

  auto screen = ftxui::ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);
}
}  // namespace RootModule