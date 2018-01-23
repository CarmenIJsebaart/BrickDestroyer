#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "ball.h"
#include "paddle.h"

///Create program window
sf::RenderWindow * create_window(
  const int window_height = 600,
  const int window_width = 500);

///Draw a particular state of the program on the window
void draw_on_window(
  sf::RenderWindow &window,
  const Ball &ball,
  const Paddle &paddle);

///Draw the game on the window
void game_on_screen(
  sf::RenderWindow &window,
  const Ball &ball,
  const Paddle &paddle);

#endif // WINDOW_H
