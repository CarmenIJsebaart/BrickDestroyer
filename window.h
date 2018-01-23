#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

#include "ball.h"

sf::RenderWindow * create_window(
  const int window_height = 600,
  const int window_width = 500);

void draw_on_window(
  sf::RenderWindow &window,
  const Ball &ball
);

void game_on_screen(
  sf::RenderWindow &window,
  const Ball &ball
);

#endif // WINDOW_H
