#include "paddle.h"

Paddle::Paddle(
  const sf::Vector2f &any_position,
  const float height,
  const float width,
  const sf::Color color
) : m_color{color},
    m_position{any_position},
    m_height{height},
    m_width{width}
{
}

///Create paddle
Paddle create_paddle(
  const int window_height,
  const int window_width)
{
  //Create a paddle with these parameters:
  const int height = 5;
  const int width = 30;
  Paddle paddle(
    sf::Vector2f(),
    height,
    width,
    sf::Color::Blue)
}
