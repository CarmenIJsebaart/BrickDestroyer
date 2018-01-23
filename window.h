#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

sf::RenderWindow * create_window(
  const int window_height = 400,
  const int window_width = 600);

void draw_on_window(
  sf::RenderWindow &window,
  const sf::CircleShape &ball
);

void game_on_screen(
  sf::RenderWindow &window,
  const sf::CircleShape &ball
);

#endif // WINDOW_H
