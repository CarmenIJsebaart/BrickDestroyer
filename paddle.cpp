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
  const int height = 10;
  const int width = 100;
  Paddle paddle(
    sf::Vector2f((window_width/2)-(0.5*width), window_height - height),
    height,
    width,
    sf::Color::Blue);

  return paddle;
}

///Get how the paddle looks like (color, position, size, shape)
sf::RectangleShape get_shape(
  const Paddle &paddle)
{
  sf::RectangleShape paddle_shape;
  paddle_shape.setSize(sf::Vector2f(paddle.get_width(), paddle.get_height()));
  paddle_shape.setPosition(paddle.get_position());
  paddle_shape.setFillColor(paddle.get_color());
  return paddle_shape;
}
