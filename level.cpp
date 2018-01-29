#include "level.h"

Level::Level(
) : m_grid(10, 10, 10)
{
  m_grid = create_grid();
}

Level create_level()
{
  // nost vexing parse
  Level level;
  return level;
}

void draw_level(
  sf::RenderWindow &window,
  const Level &level)
{
  draw_grid(window, level.get_grid());
}
