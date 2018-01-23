#include "ball.h"

#include <iostream>
Ball::Ball(const sf::Vector2f &any_position,
  const float size,
  sf::Color color)
  : m_color{color},
    m_position{any_position},
    m_size{size}
{
}

Ball create_ball(
  const int window_height,
  const int window_width
)
{
  const int size = 5;
  Ball ball(
    sf::Vector2f(window_height/2, window_width/2),
    size,
    sf::Color::White
  );
  return ball;
}

sf::CircleShape get_shape(
  const Ball &ball)
{
  sf::CircleShape ball_shape;
  ball_shape.setRadius(ball.get_size());
  ball_shape.setPosition(ball.get_position());
  ball_shape.setFillColor(ball.get_color());
  return ball_shape;
}
