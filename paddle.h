#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle
{
public:

  ///Create the paddle
  Paddle(
    const sf::Vector2f &any_position,
    const float height,
    const float width,
    const sf::Color color
  );

private:

  sf::Color m_color;
  sf::Vector2f m_position;
  float m_height;
  float m_width;
};

///Create paddle
Paddle create_paddle(
  const int window_height,
  const int window_width
);

///Get how the paddle looks like (color, position, size, shape)
sf::RectangleShape get_shape(
  const Paddle &paddle
);

#endif // PADDLE_H
