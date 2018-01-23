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

  ///Run the program
  void run();

  ///One tick in the program
  void tick();

private:

  sf::Clock m_clock;
  Ball m_ball;
  Paddle m_paddle;
  std::unique_ptr<sf::RenderWindow> m_window;

  ///Process events
  void process_poll_events();
};

#endif // GAME_H
