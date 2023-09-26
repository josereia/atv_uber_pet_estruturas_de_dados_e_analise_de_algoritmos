#include "chauffeur_module.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include "ftxui/component/component_base.hpp"

namespace ChauffeurModule {
ftxui::Component page() {
  using namespace ftxui;

  return Renderer(Container::Vertical({}), [&] {
    auto table = Table({
        {"Nome", "Sobrenome", "Telefone", "E-mail", "CNH"},
        {"João", "Sereia", "(00) 0 0000-0000", "joao.sereia@uberpet.com.br", "Válida"},
        {"Guilherme", "Maffei", "(11) 1 1111-1111", "guilherme.maffei@uberpet.com.br", "Válida"},
        
    });

    table.SelectAll().Border(LIGHT);
    table.SelectAll().DecorateAlternateRow(bgcolor(Color::Grey27), 2, 1);
    table.SelectColumn(0).Border(LIGHT);
    table.SelectRow(0).Decorate(bold);
    table.SelectRow(0).SeparatorVertical(LIGHT);
    table.SelectRow(0).Border(DOUBLE);

    return ftxui::flex(table.Render()) | border;
  });
}
}  // namespace ChauffeurModule