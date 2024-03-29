#include "ppx-app/internal/pch.hpp"
#include "ppx-app/shapes/oriented_circle.hpp"

namespace ppx
{
void oriented_circle::draw(lynx::window2D &win) const
{
    lynx::ellipse2D::draw(win);
    m_line.parent(&transform);
    m_line.draw(win);
}
} // namespace ppx