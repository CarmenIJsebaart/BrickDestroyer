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

Grid create_grid_fire_flower(
  const sf::RenderWindow &window)
{
  //Create a grid with these parameters
  const int horizontal_squares = 16;
  const int vertical_squares = 16;
  const int brick_height = window.getSize().y / vertical_squares * 0.5;
  const int brick_width = window.getSize().x / horizontal_squares;

  Grid grid(
    horizontal_squares,
    vertical_squares,
    brick_height,
    brick_width
  );

  using sf::Color;
  //Row 1
  grid.set_row_colors(0,
    {
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black
    }
  );
  for (int row: {1, 7} )
  {
    grid.set_row_colors(
      row,
    {
      Color::Black,
      Color::Black,
      Color::White,
      Color::White,
      Color::Red,
      Color::Red,
      Color::Red,
      Color::Red,
      Color::Red,
      Color::Red,
      Color::Red,
      Color::Red,
      Color::White,
      Color::White,
      Color::Black,
      Color::Black
    }
  );
  }
  for (int row: {2, 6} )
  {
    grid.set_row_colors(
      row,
      {
        Color::Black,
        Color::White,
        Color::Red,
        Color::Red,
        Color::Red,
        Color(255,128,0),
        Color(255,128,0),
        Color(255,128,0),
        Color(255,128,0),
        Color(255,128,0),
        Color(255,128,0),
        Color::Red,
        Color::Red,
        Color::Red,
        Color::White,
        Color::Black
      }
    );
  }
  for (int row: {3, 5} )
  {
    grid.set_row_colors(
      row,
      {
        Color::White,
        Color::Red,
        Color::Red,
        Color(255,128,0),
        Color(255,128,0),
        Color::Yellow,
        Color::Black,
        Color::Yellow,
        Color::Yellow,
        Color::Black,
        Color::Yellow,
        Color(255,128,0),
        Color(255,128,0),
        Color::Red,
        Color::Red,
        Color::White
      }
    );
  }
  grid.set_row_colors(
    4,
    {
      Color::White,
      Color::Red,
      Color::Red,
      Color(255,128,0),
      Color::Yellow,
      Color::White,
      Color::Black,
      Color::White,
      Color::White,
      Color::Black,
      Color::White,
      Color::Yellow,
      Color(255,128,0),
      Color::Red,
      Color::Red,
      Color::White
    }
  );
  grid.set_row_colors(8,
    {
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black
    }
  );
  grid.set_row_colors(9,
    {
      sf::Color::Black,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Black
    }
  );
  grid.set_row_colors(10,
    {
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Black,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::Black,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White
    }
  );
  grid.set_row_colors(11,
    {
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White
    }
  );
  grid.set_row_colors(12,
    {
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White
    }
  );
  grid.set_row_colors(13,
    {
      sf::Color::Black,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::Black
    }
  );
  grid.set_row_colors(14,
    {
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::Green,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Black,
      sf::Color::Black
    }
  );
  grid.set_row_colors(15,
    {
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::White,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black,
      sf::Color::Black
    }
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

void Grid::set_row_colors(
  const int y,
  const std::vector<sf::Color>& colors
)
{
  const int maxx = colors.size();
  for (int x = 0; x != maxx; ++x)
  {
    set_color(x, y, colors[x]);
  }
}
