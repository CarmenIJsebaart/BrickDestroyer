#include "ball.h"

Ball::Ball(
  const sf::Vector2f &any_position,
  const float size,
  sf::Color color,
  const float any_speed_x,
  const float any_speed_y
) : m_color{color},
    m_position{any_position},
    m_size{size},
    m_speed_x{any_speed_x},
    m_speed_y{any_speed_y}
{
}

///Create ball
Ball create_ball(
  const int window_height,
  const int window_width)
{
  //Create a white ball with size 5 in the middle of the screen
  const int size = 5;
  const float speed_x = 0.5;
  const float speed_y = 0.5;
  Ball ball(
    sf::Vector2f(window_height/2, window_width/2),
    size,
    sf::Color::White,
    speed_x,
    speed_y
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
  const float curr_x_pos = ball.get_position().x;
  const float speed_x = ball.get_speed_x();
  float new_x_pos = curr_x_pos + speed_x;

  //Calculate new y-position
  const float curr_y_pos = ball.get_position().y;
  const float speed_y = ball.get_speed_y();
  float new_y_pos = curr_y_pos + speed_y;

  //Set the new position of the ball
  ball.set_position(sf::Vector2f(new_x_pos, new_y_pos));
}

///Set the position of the ball
void Ball::set_position(
  const sf::Vector2f &any_position)
{
  m_position = any_position;
}
