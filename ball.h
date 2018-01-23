#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
public:

  //Create the ball with m_position as the initial position
  Ball(
    const sf::Vector2f &any_position,
    const float size,
    sf::Color color
  );

  sf::Color get_color() const noexcept { return m_color; }
  sf::Vector2f get_position() const noexcept { return m_position; }
  float get_size() const noexcept { return m_size; }

  void set_position(
    const sf::Vector2f &any_position
  );

private:

  sf::Color m_color;
  sf::Vector2f m_position;
  float m_size;

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
