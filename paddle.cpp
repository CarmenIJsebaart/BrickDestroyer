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
    sf::Vector2f((window_width/2)-(0.5*width), window_height - 2*height),
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

///Prevent the paddle from exiting the window
void keep_paddle_in_window(
  const sf::RenderWindow &window,
  Paddle &paddle)
{
  const int paddle_width = paddle.get_width();
  const int window_width = window.getSize().x;

  //Get y-position of the paddle
  const float pos_y = paddle.get_position().y;

  //Check the left wall
  if(sf::Mouse::getPosition(window).x <= (paddle_width*0.5))
  {
    paddle.set_position(sf::Vector2f(0, pos_y));
  }

  //Check the right wall
  if(sf::Mouse::getPosition(window).x >= (window_width - (0.5*paddle_width)))
  {
    paddle.set_position(sf::Vector2f(window_width - paddle_width, pos_y));
  }
}

///Move the paddle
void move(
  const sf::RenderWindow &window,
  Paddle &paddle)
{
  //Calculate the x-position of the paddle
  float x_pos = sf::Mouse::getPosition(window).x - (paddle.get_width()*0.5);

  //Always use the same y-position
  const float y_pos = paddle.get_position().y;

  //Set the new position of the paddle
  paddle.set_position(sf::Vector2f(x_pos, y_pos));
}

///Set the position of the paddle
void Paddle::set_position(
  const sf::Vector2f &any_position)
{
  m_position = any_position;
}
