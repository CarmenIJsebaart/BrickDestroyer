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

  Ball m_ball;
  sf::Clock m_clock;
  bool m_is_game_over{false};
  Paddle m_paddle;
  std::unique_ptr<sf::RenderWindow> m_window;
  Level m_level; //Current level

  void draw_game_over();

  ///Process events
  void process_poll_events();
};

#endif // GAME_H
