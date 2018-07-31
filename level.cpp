#include "level.h"

Level::Level(
  const sf::RenderWindow &window
) : m_grid(10, 10, 10, 10)
{
  //m_grid = create_grid_fire_flower(window);
  m_grid = create_test_grid(window);
}

///Create leveel
Level create_level(
  const sf::RenderWindow &window)
{
  Level level(window);
  return level;
}

///Draw the level on the window
void draw_level(
  sf::RenderWindow &window,
  const Level &level)
{
  draw_grid(window, level.get_grid());
}

bool Level::is_empty() const
{
  return m_grid.is_empty();
}
