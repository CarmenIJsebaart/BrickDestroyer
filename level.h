#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "grid.h"

/// A level has a grid (of colors)
class Level
{
public:
  Level();

  const Grid& get_grid() const noexcept { return m_grid; }

private:

  Grid m_grid;

};

Level create_level();

void draw_level(
  sf::RenderWindow &window,
  const Level &level);

#endif // LEVEL_H
