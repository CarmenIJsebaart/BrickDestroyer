#include "game.h"

#include "window.h"

Game::Game()
  : ball{},
    window{create_window()}
{
  //ball = create_ball();
}

///Run the game
void Game::run()
{
  while(window->isOpen())
  {
    tick();
  }
}

///This happens every tick in the game
void Game::tick()
{
  //process_poll_events();
  const double update_time = 10;

  if(clock.getElapsedTime().asMilliseconds() >= update_time)
  {
    ball.move(sf::Vector2f(10,10));
    clock.restart();
  }

  draw_on_window(*window, ball);
}
