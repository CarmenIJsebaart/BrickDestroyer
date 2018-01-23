#include "window.h"

///Create program window
sf::RenderWindow * create_window(
  const int window_height,
  const int window_width)
{
  return new sf::RenderWindow(
             sf::VideoMode(window_width, window_height),
             "BrickDestroyer",
             sf::Style::Titlebar | sf::Style::Close);
}

///Draw a particular state of the program on the window
void draw_on_window(
  sf::RenderWindow &window,
  const Ball &ball)
{
  game_on_screen(window, ball);
}

///Draw the game on the window
void game_on_screen(
  sf::RenderWindow & window,
  const Ball &ball)
{
  window.clear();
  window.draw(get_shape(ball));
  window.display();
}
