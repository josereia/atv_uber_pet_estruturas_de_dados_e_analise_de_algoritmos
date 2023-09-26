#include "chauffeur_module.hpp"
#include <ftxui/dom/table.hpp>
#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/util/ref.hpp"

ftxui::Component table() {
  using namespace ftxui;

  return Renderer(Container::Vertical({}), [&] {
    auto table = Table({
        {"Nome", "Sobrenome", "Telefone", "E-mail", "CNH"},
        {"João", "Sereia", "(00) 0 0000-0000", "joao.sereia@uberpet.com.br",
         "Válida"},
        {"Guilherme", "Maffei", "(11) 1 1111-1111",
         "guilherme.maffei@uberpet.com.br", "Válida"},

    });

    table.SelectAll().Border(LIGHT);
    table.SelectAll().Separator(LIGHT);
    table.SelectAll().DecorateAlternateRow(bgcolor(Color::Grey27), 2, 1);
    table.SelectColumn(0).Border(LIGHT);
    table.SelectRow(0).Decorate(bold);
    table.SelectRow(0).SeparatorVertical(LIGHT);
    table.SelectRow(0).Border(DOUBLE);

    return table.Render();
  });
}

namespace ChauffeurModule {
ftxui::Component page() {
  using namespace ftxui;

  std::string search;

  auto inputComponent = Input(&search, "Pesquise um motorista");

  auto container = Container::Vertical({});

  return Renderer(container, [&] {
    return flex({
        vbox({
            flex({
                table()->Render(),
            }),
            hbox({

            }),
        }),
    });
  });
}
}  // namespace ChauffeurModule