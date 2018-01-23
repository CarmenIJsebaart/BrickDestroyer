#include "window.h"

sf::RenderWindow * create_window(
  const int window_height,
  const int window_width)
{
  return new sf::RenderWindow(
             sf::VideoMode(window_width, window_height),
             "BrickDestroyer",
             sf::Style::Titlebar | sf::Style::Close);
}

void draw_on_window(
  sf::RenderWindow &window,
  const sf::CircleShape &ball)
{
  game_on_screen(window, ball);
}

void game_on_screen(
  sf::RenderWindow & window,
  const sf::CircleShape &ball)
{
  window.clear();
  window.draw(ball);
  window.display();
}
