#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "level.h"
#include "window.h"

/// A game displays the level, paddles, balls, players, etc.
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
  Level m_level; //Current level
  Paddle m_paddle;
  std::unique_ptr<sf::RenderWindow> m_window;

  ///Process events
  void process_poll_events();
};

#endif // GAME_H
