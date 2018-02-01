#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>

/// A grid of colors, where black denotes
/// an empty square, all other colors a brick x
class Grid
{
public:
  Grid(
    const int horizontal_squares,
    const int vertical_squares,
    const int block_height,
    const int block_width
  );

  sf::Color get(const int x, const int y) const noexcept { return m_v[y][x]; }
  int get_horizontal_squares() const noexcept { return m_v.size(); }
  int get_block_height() const noexcept { return m_block_height; }
  int get_block_width() const noexcept { return m_block_width; }
  int get_vertical_squares() const noexcept { return m_v[0].size(); }

private:

  std::vector<std::vector<sf::Color>> m_v;
  int m_block_height;
  int m_block_width;

};

Grid create_grid(
  const sf::RenderWindow &window
);

void draw_grid(
  sf::RenderWindow &window,
  const Grid &grid);

#endif // GRID_H
