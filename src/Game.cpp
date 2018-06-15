/**********************************************************************************************************************************
* Copyright (c) 2017-2018 El F. Percy
* Standard Header. 
*
* This project is One Piece: Gigant Battle! 2 New World almost copy. 
* I do not take any advantages of this project and resources taken from OP: GB! 2 are for learning purposes. 
* Under this message I list all people, companies or organization which materials I've used in this project:
* - Hopson97: Structure of this game is based on his structures of games. Link:
* - Bandai Namco Entertainment and Shūeisha published One Piece: Gigant Battle! 2 New World. 
*   I used many features of their product (including texture, sound etc.) 
*
* MIT License
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
**********************************************************************************************************************************/

#include "Game.h"

#include <iostream>
#include "States/State_base.h"
#include "States/Menu_state.h"

Game::Game()
  :m_resource_manager{},
   m_music_player{m_resource_manager},
   m_last_time{0}
{
  m_window.create(sf::VideoMode(m_win_width,m_win_height), "One Piece: C",sf::Style::Fullscreen); //initializing window 
  change_state(new Menu_state(this));

  m_window.setFramerateLimit(60); // set max. FPS to 60

  //m_arial.loadFromFile("fonts/arial.ttf");
  m_frames_per_second.setFont(m_arial);
}

// main logic function. It runs main loop of the program.
// manages time and states
void Game::run_main_loop()
{
    sf::Clock mclock;
    sf::Clock infinite_clock;
    float delta_time = 0.0f;  //Set delta time
    sf::Time time_since_start; //Elapsed time
    while(m_window.isOpen())
    {
      delta_time = mclock.restart().asSeconds();  //Set delta time
      time_since_start = infinite_clock.getElapsedTime(); //Elapsed time

      window_event();

      auto state_guard = m_state;
      m_state->logic(delta_time,time_since_start.asSeconds());

      //display_fps(current_time);

      m_window.display();
    }
}

// changes current state
void Game::change_state(State* state)
{
  m_state.reset(std::move(state)); //Reset the state to the state in the argument
}

int Game::get_win_width() const
{
  return m_win_width;
}

int Game::get_win_height() const
{
  return m_win_height;
}

// returns reference to resource_manager
Resource_manager& Game::get_resource_manager()
{
  return m_resource_manager;
}

// returns reference to music_player
Music_player& Game::get_music_player()
{
  return m_music_player;
}

// returns reference to event 
sf::Event& Game::get_event() 
{
  return m_event;
}

// returns reference to render_window
sf::RenderWindow& Game::get_render_window() 
{
  return m_window;
}

// handles all window events
void Game::window_event()
{
    m_window.clear();
  
    while(m_window.pollEvent(m_event))
    {   
        if (m_event.type == sf::Event::Closed)
          m_window.close();
    }
}

// display number of frames per second. WIP
void Game::display_fps(float current_time)
{

}