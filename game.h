#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "ball.h"

class Game
{
public:
  Game();

  void run();
  void tick();

private:

  sf::Clock clock;
  Ball ball;
  std::unique_ptr<sf::RenderWindow> window;
};

#endif // GAME_H
