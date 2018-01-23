#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
public:

  ///Create the ball with m_position as the initial position
  Ball(
    const sf::Vector2f &any_position,
    const float size,
    sf::Color color,
    const float any_speed_x,
    const float any_speed_y
  );

  ///Get the color of the ball
  sf::Color get_color() const noexcept { return m_color; }

  ///Get the position of the ball
  sf::Vector2f get_position() const noexcept { return m_position; }

  ///Get the size of the ball
  float get_size() const noexcept { return m_size; }

  ///Get the x-speed of the ball
  float get_speed_x() const noexcept { return m_speed_x; }

  ///Get the y-speed of the ball
  float get_speed_y() const noexcept { return m_speed_y; }

  ///Set the position of the ball
  void set_position(
    const sf::Vector2f &any_position
  );

private:

  sf::Color m_color;
  sf::Vector2f m_position;
  float m_size;
  float m_speed_x;
  float m_speed_y;

};

Ball create_ball(
  const int window_height,
  const int window_width
);

void move(
  Ball &ball
);

sf::CircleShape get_shape(
  const Ball &ball
);

#endif // BALL_H
