#include "chauffeur_module.hpp"
#include <algorithm>
#include <ftxui/dom/table.hpp>
#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/util/ref.hpp"

ftxui::Component table(std::__1::vector<std::__1::vector<std::__1::string>> data) {
  using namespace ftxui;

  return Renderer(Container::Vertical({}), [&] {
    auto table = Table(data);

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
std::string search;

ftxui::Component page() {
  using namespace ftxui;

  std::__1::vector<std::__1::vector<std::__1::string>> content = {
      {"Nome", "Sobrenome", "Telefone", "E-mail", "CNH"},
      {"João", "Sereia", "(00) 0 0000-0000", "joao.sereia@uberpet.com.br",
       "Válida"},
      {"Guilherme", "Maffei", "(11) 1 1111-1111",
       "guilherme.maffei@uberpet.com.br", "Válida"},
  };

  // Vetor para armazenar os subvetores filtrados
  std::__1::vector<std::__1::vector<std::__1::string>> filtered;

  InputOption option;
  option.on_enter = [&] {};
  option.on_change = [&] {
    // Usar std::copy_if com uma função lambda como critério de filtragem
    std::copy_if(content.begin(), content.end(), std::back_inserter(filtered),
                 [&](const std::vector<std::string>& subvetor) {
                   // Substitua esta condição pelo seu critério de filtragem
                   return std::find(subvetor.begin(), subvetor.end(), search) !=
                          subvetor.end();
                 });
  };

  auto inputComponent = Input(&search, "Pesquise um motorista", option);
  auto container = Container::Vertical({
      Container::Horizontal({
          inputComponent | frame | size(HEIGHT, LESS_THAN, 10),
          Button("Criar novo", [] {}),
      }),
      table(filtered),
  });

  return container;
}
}  // namespace ChauffeurModule