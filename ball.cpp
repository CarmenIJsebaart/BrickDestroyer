#include "ball.h"

Ball::Ball(
  const sf::Vector2f &any_position,
  const float size,
  sf::Color color
) : m_color{color},
    m_position{any_position},
    m_size{size}
{
}

///Create ball
Ball create_ball(
  const int window_height,
  const int window_width)
{
  const int size = 5;
  Ball ball(
    sf::Vector2f(window_height/2, window_width/2),
    size,
    sf::Color::White
  );
  return ball;
}

///Get how the ball looks like (color, position, size, shape)
sf::CircleShape get_shape(
  const Ball &ball)
{
  sf::CircleShape ball_shape;
  ball_shape.setRadius(ball.get_size());
  ball_shape.setPosition(ball.get_position());
  ball_shape.setFillColor(ball.get_color());
  return ball_shape;
}

///Move the ball
void move(
  Ball &ball)
{
  //Calculate new x-position
  const auto curr_x_pos = ball.get_position().x;
  auto new_x_pos = curr_x_pos + 0.5;

  //Calculate new y-position
  const auto curr_y_pos = ball.get_position().y;
  auto new_y_pos = curr_y_pos + 0.5;

  //Set the new position of the ball
  ball.set_position(sf::Vector2f(new_x_pos, new_y_pos));
}

void Ball::set_position(
  const sf::Vector2f &any_position)
{
  m_position = any_position;
}
