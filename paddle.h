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

  ///Get the color of the paddle
  sf::Color get_color() const noexcept { return m_color; }

  ///Get the height of the paddle
  float get_height() const noexcept { return m_height; }

  ///Get the position of the paddle
  sf::Vector2f get_position() const noexcept { return m_position; }

  ///Get the width of the paddle
  float get_width() const noexcept { return m_width; }

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
