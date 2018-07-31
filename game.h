#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "level.h"
#include "window.h"

enum class GameState
{
  running,
  game_over,
  game_won,
  level_won
};

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
  GameState m_game_state{GameState::running};
  Paddle m_paddle;
  std::unique_ptr<sf::RenderWindow> m_window;
  Level m_level; //Current level

  bool has_finished_level() const;

  void draw_game_over();
  void draw_level_won();

  ///Process events
  void process_poll_events();
};

#endif // GAME_H
