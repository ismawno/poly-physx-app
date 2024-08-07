#pragma once

#include "lynx/drawing/drawable.hpp"

namespace ppx
{
class joint_repr2D : public lynx::drawable2D
{
  public:
    virtual ~joint_repr2D() = default;

    virtual void update(float sleep_greyout) = 0;
};
} // namespace ppx