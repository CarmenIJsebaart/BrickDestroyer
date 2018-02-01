#include "grid.h"

#include <iostream>

Grid::Grid(const int horizontal_squares,
  const int vertical_squares,
  const int block_height,
  const int block_width
) : m_v(vertical_squares, std::vector<sf::Color>(horizontal_squares, sf::Color::Yellow)),
    m_brick_height{block_height},
    m_brick_width{block_width}
{
}

///Create grid
Grid create_grid(
  const sf::RenderWindow &window)
{
  //Create a grid with these parameters
  const int horizontal_squares = 10;
  const int vertical_squares = 15;
  const int block_height = window.getSize().y / vertical_squares * 0.5;
  const int block_width = window.getSize().x / horizontal_squares;

  Grid grid(
    horizontal_squares,
    vertical_squares,
    block_height,
    block_width
  );

  return grid;
}

///Draw the grid on the window
void draw_grid(
  sf::RenderWindow &window,
  const Grid &grid)
{
  const int block_height = grid.get_brick_height();
  const int block_width = grid.get_brick_width();
  const int n_cols = grid.get_horizontal_squares();
  const int n_rows = grid.get_vertical_squares();

  for (int x = 0; x != n_rows; ++x)
  {
    for (int y = 0; y != n_cols; ++y)
    {
      const sf::Color c = grid.get(x,y);
      sf::RectangleShape s;
      s.setFillColor(c);
      s.setPosition(x * block_width, y * block_height);
      s.setSize(sf::Vector2f(block_width, block_height));
      s.setOutlineThickness(-1);
      s.setOutlineColor(sf::Color::Black);
      window.draw(s);
    }
  }
}
