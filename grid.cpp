#include "grid.h"

#include <cassert>
#include <iostream>

Grid::Grid(
  const int horizontal_squares,
  const int vertical_squares,
  const int brick_height,
  const int brick_width
) : m_v(vertical_squares, std::vector<sf::Color>(horizontal_squares, sf::Color::Yellow)),
    m_brick_height{brick_height},
    m_brick_width{brick_width}
{
  assert(get_horizontal_squares() == horizontal_squares);
  assert(get_vertical_squares() == vertical_squares);
}

///Create grid
Grid create_grid(
  const sf::RenderWindow &window)
{
  //Create a grid with these parameters
  const int horizontal_squares = 10;
  const int vertical_squares = 15;
  const int brick_height = window.getSize().y / vertical_squares * 0.5;
  const int brick_width = window.getSize().x / horizontal_squares;

  Grid grid(
    horizontal_squares,
    vertical_squares,
    brick_height,
    brick_width
  );

  return grid;
}

///Draw the grid on the window
void draw_grid(
  sf::RenderWindow &window,
  const Grid &grid)
{
  const int brick_height = grid.get_brick_height();
  const int brick_width = grid.get_brick_width();
  const int n_cols = grid.get_horizontal_squares();
  const int n_rows = grid.get_vertical_squares();

  for (int y = 0; y != n_rows; ++y)
  {
    for (int x = 0; x != n_cols; ++x)
    {
      const sf::Color c = grid.get_color(x,y);
      sf::RectangleShape s;
      s.setFillColor(c);
      s.setPosition(x * brick_width, y * brick_height);
      s.setSize(sf::Vector2f(brick_width, brick_height));
      s.setOutlineThickness(-1);
      s.setOutlineColor(sf::Color::Black);
      window.draw(s);
    }
  }
}

void Grid::set_color(
  const int x,
  const int y,
  const sf::Color color)
{
  m_v[y][x] = color;

  assert(get_color(x, y) == color);
}
