#include "game.h"

Game::Game(
) : m_ball(sf::Vector2f(), 0.0, sf::Color::Black, 0.0, 0.0),
    m_level{},
    m_paddle{sf::Vector2f(), 0.0, 0.0, sf::Color::Black},
    m_window{create_window()}
{
  m_ball = create_ball(m_window->getSize().y, m_window->getSize().x);
  m_level = create_level();
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
  const double update_time = 10;

  if(m_clock.getElapsedTime().asMilliseconds() >= update_time)
  {
    //Check for events
    process_poll_events();

    //Keep paddle in the window
    keep_paddle_in_window(*m_window, m_paddle);

    //Move and keep ball in window
    move(m_ball);
    keep_ball_in_window(*m_window, m_ball);

    //Check for collision
    if(are_colliding(m_ball, m_paddle))
    {
      change_y_direction(m_ball);
      move(m_ball);
    }

    //Restart clock
    m_clock.restart();
  }

  //Draw all components on the window
  draw_on_window(*m_window, m_level, m_ball, m_paddle);
}
