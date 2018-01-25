#include "game.h"

Game::Game(
) : m_ball(sf::Vector2f(), 0.0, sf::Color::Black, 0.0, 0.0),
    m_paddle{sf::Vector2f(), 0.0, 0.0, sf::Color::Black},
    m_window{create_window()}
{
  m_ball = create_ball(m_window->getSize().y, m_window->getSize().x);
  m_paddle = create_paddle(m_window->getSize().y, m_window->getSize().x);
}

///Run the program
void Game::run()
{
  while(m_window->isOpen())
  {
    tick();
  }
}

///Process events
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
      case sf::Event::MouseMoved:
        move(*m_window, m_paddle);
      default:
        break;
    }
  }
}

///This happens every tick in the program
void Game::tick()
{
  process_poll_events();
  const double update_time = 10;

  if(m_clock.getElapsedTime().asMilliseconds() >= update_time)
  {
    move(m_ball);
    keep_ball_in_window(*m_window, m_ball);
    m_clock.restart();
  }

  draw_on_window(*m_window, m_ball, m_paddle);
}
