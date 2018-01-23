#include "ball.h"

Ball::Ball(
  const sf::Vector2f &any_position,
  const float size,
  sf::Color color,
  const int window_height,
  const int window_width
) : m_color{color},
    m_position{any_position},
    m_size{size},
    m_window_height{window_height},
    m_window_width{window_width}
{
}

Ball create_ball(
  const int window_height,
  const int window_width
)
{
  const int size = 10;
  Ball ball(
    sf::Vector2f((window_width / 2) - size, window_height - (size * 2)),
    size,
    sf::Color::White,
    window_height,
    window_width
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
