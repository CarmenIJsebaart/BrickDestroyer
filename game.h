#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "window.h"

class Game
{
public:
  Game();

  void run();
  void tick();

private:

  sf::Clock m_clock;
  Ball m_ball;
  std::unique_ptr<sf::RenderWindow> m_window;

  void process_poll_events();
};

#endif // GAME_H
