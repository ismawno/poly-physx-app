#pragma once

#include "ppx-app/drawables/lines/spring_line.hpp"
#include "ppx-app/drawables/joints/joint_repr.hpp"
#include "ppx/joints/spring_joint.hpp"

namespace ppx
{
class spring_repr2D final : public joint_repr2D
{
  public:
    spring_repr2D(const spring_joint2D *sj, const lynx::color &color, float sleep_greyout);

  private:
    const spring_joint2D *m_sj;
    spring_line2D m_line;
    lynx::color m_color;

    void update(float sleep_greyout) override;
    void draw(lynx::window2D &window) const override;
};
} // namespace ppx