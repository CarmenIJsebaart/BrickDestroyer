#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "grid.h"

///A level has a grid (of colors)
class Level
{
public:
  Level(
    const sf::RenderWindow &window
  );

  ///Get the grid
  const Grid& get_grid() const noexcept { return m_grid; }
        Grid& get_grid() noexcept { return m_grid; }

  ///Returns true if all grid cells are black
  bool is_empty() const;

private:

  Grid m_grid;

};

///Create level
Level create_level(
  const sf::RenderWindow &window
);

///Draw the level on the window
void draw_level(
  sf::RenderWindow &window,
  const Level &level);

#endif // LEVEL_H
