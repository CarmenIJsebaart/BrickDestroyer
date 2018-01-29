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
    const int pixel_size
  );

  sf::Color get(const int x, const int y) const noexcept { return m_v[y][x]; }
  int get_horizontal_squares() const noexcept { return m_v.size(); }
  int get_pixel_size() const noexcept { return m_pixel_size; }
  int get_vertical_squares() const noexcept { return m_v[0].size(); }

private:

  std::vector<std::vector<sf::Color>> m_v;
  int m_pixel_size;

};

Grid create_grid();

void draw_grid(
  sf::RenderWindow &window,
  const Grid &grid);

#endif // GRID_H
