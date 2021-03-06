#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "level.h"
#include "paddle.h"

enum Collision
{
  no,  //No collision
  hor, //Horizontally
  ver  //Vertically
};

class Ball
{
public:

  ///Create the ball
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

  ///Set the x-speed of the ball
  void set_speed_x(
    const float &any_speed_x);

  ///Set the y-speed of the ball
  void set_speed_y(
    const float &any_speed_y);

private:

  sf::Color m_color;
  sf::Vector2f m_position;
  float m_size;
  float m_speed_x;
  float m_speed_y;

};

///Check for collision between ball and bricks
///Can be none, vertical or horizontal
Collision get_collision(
  const Ball &ball,
  Level &level
);

///Check for collision between ball and paddle
bool get_collision(
  const Ball &ball,
  const Paddle &paddle
);

///Change the direction of the ball, according to the collision side
void change_direction(
  Ball &ball
);

///Change the x-direction of the ball after collision
void change_x_direction(
  Ball &ball
);

///Change the y-direction of the ball after collision
void change_y_direction(
  Ball &ball
);

///Create ball
Ball create_ball(
  const int window_height,
  const int window_width
);

///Get how the ball looks like (color, position, size, shape)
sf::CircleShape get_shape(
  const Ball &ball
);

///Prevent the ball from exiting the window
void keep_ball_in_window(
  const sf::RenderWindow &window,
  Ball &ball
);

///Move the ball
void move(
  Ball &ball
);

///Does the ball leave the screen at the bottom?
bool player_has_died(
  const sf::RenderWindow &window,
  const Ball &ball
);

#endif // BALL_H
