#include "game.h"

Game::Game(
) : m_ball(sf::Vector2f(), 0.0, sf::Color::Black),
    m_window{create_window()}
{
  m_ball = create_ball(m_window->getSize().x, m_window->getSize().y);
}

///Run the game
void Game::run()
{
  while(m_window->isOpen())
  {
    tick();
  }
}

void Game::process_poll_events()
{
  sf::Event event;
  while(m_window->pollEvent(event))
  {
    switch(event.type)
    {
      case sf::Event::Closed:
        m_window->close();
        break;
      default:
        break;
    }
  }
}

///This happens every tick in the game
void Game::tick()
{
  process_poll_events();
  const double update_time = 10;

  if(m_clock.getElapsedTime().asMilliseconds() >= update_time)
  {
    //ball.move(sf::Vector2f(10,10));
    m_clock.restart();
  }

  draw_on_window(*m_window, m_ball);
}
