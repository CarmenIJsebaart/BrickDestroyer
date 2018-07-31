#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>

///A grid of colors, where black denotes
///an empty square, all other colors a brick x
class Grid
{
public:
  Grid(
    const int horizontal_squares,
    const int vertical_squares,
    const int brick_height,
    const int brick_width
  );

  ///Get the color of a brick
  sf::Color get_color(const int x, const int y) const noexcept { return m_v[y][x]; }

  ///Get the amount of horizontal bricks in the grid
  int get_horizontal_squares() const noexcept { return m_v[0].size(); }

  ///Get the height of a brick in the grid
  int get_brick_height() const noexcept { return m_brick_height; }

  ///Get the width of a brick in the grid
  int get_brick_width() const noexcept { return m_brick_width; }

  ///Get the amount of vertical bricks in the grid
  int get_vertical_squares() const noexcept { return m_v.size(); }

  ///Set the color of a brick in the grid
  void set_color(
    const int x,
    const int y,
    const sf::Color color
  );

  ///Set the colors of the brick in the grid's ith row
  void set_row_colors(
    const int y,
    const std::vector<sf::Color>& colors
  );

private:

  //Y-X ordered (first index is the y coordinator, aka number of rows)
  std::vector<std::vector<sf::Color>> m_v; //The actual grid
  int m_brick_height;
  int m_brick_width;
};

///Create the grid
Grid create_grid(
  const sf::RenderWindow &window
);

///Create the grid
Grid create_grid_fire_flower(
  const sf::RenderWindow &window
);

///Draw the grid on the window
void draw_grid(
  sf::RenderWindow &window,
  const Grid &grid);

#endif // GRID_H
