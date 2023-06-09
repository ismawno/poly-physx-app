#include "ppx-app/pch.hpp"
#include "ppx-app/menu_layer.hpp"
#include "ppx-app/app.hpp"

namespace ppx
{
    menu_layer::menu_layer() : layer("menu_layer") {}

    void menu_layer::on_attach(app *papp) { m_app = papp; }
    void menu_layer::on_render()
    {
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Exit", "ESC"))
                    m_app->window().close();
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Settings"))
            {
                bool fullscreen = (bool)(m_app->style() & sf::Style::Fullscreen);
                if (ImGui::MenuItem("Fullscreen", "F10", &fullscreen))
                    m_app->recreate_window(fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
    }
}