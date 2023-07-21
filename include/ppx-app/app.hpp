#ifndef PPX_APP_HPP
#define PPX_APP_HPP

#include "rk/tableaus.hpp"
#include "ppx/engine2D.hpp"

#include "ppx-app/thick_line.hpp"
#include "ppx-app/spring_line.hpp"

#include "lynx/app/app.hpp"
#include "lynx/drawing/shape.hpp"

#include "kit/memory/scope.hpp"

#define PPX_DEFAULT_ENTITY_COLOR glm::vec4(123.f, 143.f, 161.f, 255.f) / 255.f
#define PPX_DEFAULT_JOINT_COLOR glm::vec4(207.f, 185.f, 151.f, 255.f) / 255.f

namespace ppx
{
class revolute_joint2D;
class app : public lynx::app2D
{
  public:
    app(const rk::butcher_tableau &table = rk::rk4, std::size_t allocations = 100, const char *name = "poly-physx");
    virtual ~app() = default;

    engine2D &engine();
    const engine2D &engine() const;

    float timestep() const;
    void timestep(float ts);

    bool sync_timestep() const;
    void sync_timestep(bool sync);

    kit::time update_time() const;
    kit::time physics_time() const;
    kit::time draw_time() const;

    glm::vec4 entity_color = PPX_DEFAULT_ENTITY_COLOR;
    glm::vec4 joint_color = PPX_DEFAULT_JOINT_COLOR;

    std::uint32_t integrations_per_frame = 1;

  private:
    virtual void on_update(float ts) override;
    virtual void on_render(float ts) override;
    virtual bool on_event(const lynx::event &event) override;

    virtual void on_entity_update(const entity2D &e, lynx::shape2D &shape)
    {
    }

    engine2D m_engine;
    std::vector<kit::scope<lynx::shape2D>> m_shapes;
    std::vector<spring_line> m_spring_lines;
    std::unordered_map<const revolute_joint2D *, thick_line> m_thick_lines;

    lynx::window2D *m_window;
    lynx::orthographic2D *m_camera;
    bool m_paused = false;
    bool m_sync_timestep = true;
    float m_timestep = 1e-3f;

    kit::time m_update_time;
    kit::time m_physics_time;
    kit::time m_draw_time;

    void update_entities();
    void update_joints();

    void draw_entities() const;
    void draw_joints() const;

    void zoom(float offset);
    void move_camera();

    glm::vec2 mouse_position() const;

    void add_engine_callbacks();
};
} // namespace ppx

#endif