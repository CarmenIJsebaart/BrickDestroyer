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
    sf::Color color,
    const int window_height,
    const int window_width
  );


private:

  sf::Color m_color;
  sf::Vector2f m_position;
  float m_size;
  const int m_window_height;
  const int m_window_width;

};

Ball create_ball(
  const int window_height,
  const int window_width
);

sf::CircleShape get_shape(
  const Ball &ball
);

#endif // BALL_H
