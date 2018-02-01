#include "level.h"

Level::Level(
  const sf::RenderWindow &window
) : m_grid(10, 10, 10, 10)
{
  m_grid = create_grid(window);
}

Level create_level(
  const sf::RenderWindow &window)
{
  // nost vexing parse
  Level level(window);
  return level;
}

void draw_level(
  sf::RenderWindow &window,
  const Level &level)
{
  draw_grid(window, level.get_grid());
}
