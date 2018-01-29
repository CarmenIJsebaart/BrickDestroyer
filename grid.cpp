#include "grid.h"

#include <iostream>

Grid::Grid(
  const int horizontal_squares,
  const int vertical_squares,
  const int pixel_size
) : m_v(vertical_squares, std::vector<sf::Color>(horizontal_squares, sf::Color::Yellow)),
    m_pixel_size{pixel_size}
{

}

Grid create_grid()
{
  //Create a grid with these parameters
  const int horizontal_squares = 10;
  const int vertical_squares = 10;
  const int pixel_size = 10;
  Grid grid(
    horizontal_squares,
    vertical_squares,
    pixel_size
  );

  return grid;
}

void draw_grid(
  sf::RenderWindow &window,
  const Grid &grid)
{
  const int pixel_size = grid.get_pixel_size();
  const int n_cols = grid.get_horizontal_squares();
  const int n_rows = grid.get_vertical_squares();

  for (int x = 0; x != n_cols; ++x)
  {
    for (int y = 0; y != n_rows; ++y)
    {
      const sf::Color c = grid.get(x,y);
      sf::RectangleShape s;
      s.setFillColor(c);
      s.setPosition(x * pixel_size, y * pixel_size);
      s.setSize(sf::Vector2f(pixel_size, pixel_size));
      s.setOutlineThickness(-1);
      s.setOutlineColor(sf::Color::Black);
      window.draw(s);
    }
  }
}
