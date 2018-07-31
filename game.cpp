#include "game.h"
#include <cassert>

Game::Game(
) : m_ball(sf::Vector2f(), 0.0, sf::Color::Black, 0.0, 0.0),
    m_paddle{sf::Vector2f(), 0.0, 0.0, sf::Color::Black},
    m_window{create_window()},
    m_level{create_level(*m_window)}
{
  m_ball = create_ball(m_window->getSize().y, m_window->getSize().x);
  m_paddle = create_paddle(m_window->getSize().y, m_window->getSize().x);
}

void Game::draw_game_over()
{
  //Check for events
  //process_poll_events();
  m_window->clear();
  sf::Text text;
  text.setString("GAME OVER");
  text.setPosition(70, 250);
  text.setCharacterSize(60);
  text.setFillColor(sf::Color::Red);

  sf::Font font;
  assert(font.loadFromFile("arial.ttf"));

  text.setFont(font);
  m_window->draw(text);
  m_window->display();
}

///Run the program
void Game::run()
{
  while(m_window->isOpen())
  {
    if(!m_is_game_over)
    {
      tick();
    }
    else
    {
      draw_game_over();
    }
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

    if (player_has_died(*m_window, m_ball))
    {
      m_is_game_over = true;
      return;
    }
    keep_ball_in_window(*m_window, m_ball);

    //Check for collision between ball and paddle
    if(get_collision(m_ball, m_paddle))
    {
      change_y_direction(m_ball);
      move(m_ball);
    }

    //Check for collision between ball and bricks in the level
    const Collision collision = get_collision(m_ball, m_level);
    if (collision != Collision::no)
    {
      if (collision == Collision::ver)
      {
        change_y_direction(m_ball);
      }
      else if (collision == Collision::hor)
      {
        change_x_direction(m_ball);
      }
      move(m_ball);
    }

    //Restart clock
    m_clock.restart();
  }

  //Draw all components on the window
  draw_on_window(*m_window, m_level, m_ball, m_paddle);
}
