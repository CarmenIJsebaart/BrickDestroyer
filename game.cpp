#include "game.h"

#include "window.h"

Game::Game()
  : ball(sf::Vector2f(), 0.0, sf::Color::Black, 0, 0),
    window{create_window()}
{
  ball = create_ball(window->getSize().x, window->getSize().y);
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
    //ball.move(sf::Vector2f(10,10));
    clock.restart();
  }

  draw_on_window(*window, ball);
}
