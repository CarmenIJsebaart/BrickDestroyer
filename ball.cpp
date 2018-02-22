#include "ball.h"

#include <iostream>

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

///Check for collision between ball and bricks in the level
bool are_colliding(const Ball &ball, Level &level)
{
  //Calculate at what coordinate the ball is
  const int col = ball.get_position().x / level.get_grid().get_brick_width();
  const int row = ball.get_position().y / level.get_grid().get_brick_height();

  std::cout << col << ", " << row << "\n";

  //Is the cell a grid cell?
  if(row > level.get_grid().get_vertical_squares())
  {
    return false;
  }

  //Check the color of the brick in which the ball is
  sf::Color color = level.get_grid().get_color(col, row);

  //Check for collision
  if(color == sf::Color::Yellow)
  {
    level.get_grid().set_color(col, row, sf::Color::Black);
    return true;
  }
  else
  {
    return false;
  }
}

///Check for collision between ball and paddle
bool are_colliding(
  const Ball &ball,
  const Paddle &paddle
)
{
  //Get the position of the ball
  const float ball_pos_x = ball.get_position().x;
  const float ball_pos_y = ball.get_position().y;

  //Get the position of the paddle
  const float paddle_pos_x = paddle.get_position().x;
  const float paddle_pos_y = paddle.get_position().y;

  //Check for collision
  if(ball_pos_y + ball.get_size() >= paddle_pos_y &&
     ball_pos_x > paddle_pos_x  &&
     ball_pos_x < (paddle_pos_x + (paddle.get_width())))
  {
    return true;
  }
  else
  {
    return false;
  }
}

///Change the direction of the ball after collision
void change_x_direction(
  Ball &ball
)
{
  float curr_speed_x = ball.get_speed_x();
  float new_speed_x;
  new_speed_x = -1.0*curr_speed_x;
  ball.set_speed_x(new_speed_x);
}

///Change the direction of the ball after collision
void change_y_direction(
  Ball &ball
)
{
  float curr_speed_y = ball.get_speed_y();
  float new_speed_y;
  new_speed_y = -1.0*curr_speed_y;
  ball.set_speed_y(new_speed_y);
}

///Create ball
Ball create_ball(
  const int window_height,
  const int window_width)
{
  //Create a ball with these parameters:
  const int size = 5;
  const float speed_x = 0.75;
  const float speed_y = 0.75;
  Ball ball(
    sf::Vector2f(window_width/2, window_height/2),
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

///Prevent the ball from exiting the window
void keep_ball_in_window(
  const sf::RenderWindow &window,
  Ball &ball)
{
  //Check the right and left wall
  float x_pos = ball.get_position().x;
  if(x_pos >= (window.getSize().x - ball.get_size()) ||
     x_pos <= 0.0)
  {
    change_x_direction(ball);
  }

  //Check the lower and upper wall
  float y_pos = ball.get_position().y;
  if(y_pos >= (window.getSize().y - ball.get_size()) ||
     y_pos <= 0.0)
  {
    change_y_direction(ball);
  }
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

///Set the x-speed of the ball
void Ball::set_speed_x(
  const float &any_speed_x)
{
  m_speed_x = any_speed_x;
}

///Set the y-speed of the ball
void Ball::set_speed_y(
  const float &any_speed_y)
{
  m_speed_y = any_speed_y;
}
