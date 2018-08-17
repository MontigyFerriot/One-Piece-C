/**********************************************************************************************************************************
* Copyright (c) 2017-2018 Maciej Falkowski  
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

#include "States/Menu_state.hpp"

#include <iostream>
#include "Game.hpp"
#include "States/Play_state.hpp"

Menu_state::Menu_state(Game* game)
    :State{game},
     m_gui{game->get_render_window()},
     m_button_width{240.0f},
     m_button_height{60.0f},
     m_background_number{0},
     m_logo{m_resource_manager,"one_piece_logo.png"},
     m_background{m_resource_manager,"ace_background.png"},
     m_ace_background_animation{Standard_function_animation{0,0,200,1,game->get_win_width(),
        game->get_win_height(),0.05f,[]( int& x, int& y) { x+=1; }}},
     m_katakuri_background_animation{Standard_function_animation{0,0,1,1400,game->get_win_width(),
        game->get_win_height(),0.04f,[]( int& x, int& y) { y+=1; }}},
     m_strawhats_animation{Standard_function_animation{0,0,200,200,game->get_win_width(),
        game->get_win_height(),0.05f,[]( int& x, int& y) { x+=1; y+=1; }}},
     m_luffy_gear_second_animation{Standard_function_animation{0,0,1,315,game->get_win_width(),
        game->get_win_height(),0.05f,[]( int& x, int& y) { y+=1; }}}
{
    m_logo.get_sprite().setPosition(308.0f,-100.0f);

    m_background.get_sprite().setPosition(0.0f,0.0f);
    m_katakuri_background_animation.set_infinite_animation(true);
    m_ace_background_animation.set_infinite_animation(true);
    m_luffy_gear_second_animation.set_infinite_animation(true);
    m_strawhats_animation.set_infinite_animation(true);

    switch_to_next_background();

    set_up_gui();

    m_music_player.shuffle_play(0.6f);
}

Menu_state::~Menu_state()
{
    m_music_player.stop();
}

void Menu_state::input(float dt, float clocked_time)
{
    m_gui.handleEvent(m_game->get_event());
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        m_music_player.play();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        m_music_player.stop();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
        m_music_player.next(clocked_time);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
        m_music_player.previous(clocked_time);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T))
        m_music_player.restart(clocked_time);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y))
        m_music_player.shuffle_play(clocked_time);
}

void Menu_state::update(float dt, float clocked_time) 
{
    if(m_main_animation->is_end())
    {
        m_main_animation->restart();
        switch_to_next_background();
    }
    m_main_animation->animate(m_background.get_sprite(),clocked_time);
    //m_music_player.check_to_switch(clocked_time); // TODO: Make switching to next music when one ends.
}


void Menu_state::draw()
{
    m_background.draw(m_game->get_render_window());
    m_logo.draw(m_game->get_render_window());
    m_gui.draw();
}

void Menu_state::switch_to_next_background()
{
    int c = 0;
    while(true)
    {
        c = util::randomize(1,4);
        if(c != m_background_number)
        {
            m_background_number = c;
            break;
        }
    }

    //while((c = util::randomize(1,4)) == m_background_number);
    //m_background_number = c;

    switch(c)
    {
        case 1:
            m_background.get_sprite().setTexture(m_resource_manager.get_texture("katakuri_background.png"));
            m_main_animation = &m_katakuri_background_animation;
        break;
        case 2:
            m_background.get_sprite().setTexture(m_resource_manager.get_texture("ace_background.png"));
            m_main_animation = &m_ace_background_animation;
        break;
        case 3:
            m_background.get_sprite().setTexture(m_resource_manager.get_texture("strawhats1.png"));
            m_main_animation = &m_strawhats_animation;
        break;
        case 4:
            m_background.get_sprite().setTexture(m_resource_manager.get_texture("luffy_gear_second.png"));
            m_main_animation = &m_luffy_gear_second_animation;
        break;
        default:
            m_background.get_sprite().setTexture(m_resource_manager.get_texture("katakuri_background.png"));
            m_main_animation = &m_katakuri_background_animation;
    }
}

void Menu_state::set_up_gui()
{   
    tgui::Button::Ptr play_button = tgui::Button::create(sf::String("Play Game"));
    play_button->setSize(m_button_width,m_button_height);
    play_button->setPosition(m_half_window_width - (m_button_width / 2.0f),450);
    play_button->setInheritedOpacity(0.8f);
    play_button->setTextSize(35u);
    play_button->connect("pressed",[&]() 
    { 
        m_game->change_state(new Play_state{m_game}); 
    });
    m_gui.add(play_button);
    
    tgui::Button::Ptr option_button = tgui::Button::create(sf::String("Options"));
    option_button->setSize(m_button_width,m_button_height);
    option_button->setPosition(m_half_window_width - (m_button_width / 2.0f),550);
    option_button->setInheritedOpacity(0.8f);
    option_button->setTextSize(35u);
    option_button->setEnabled(true);
    m_gui.add(option_button);
    
    tgui::Button::Ptr exit_button = tgui::Button::create(sf::String("Exit"));
    exit_button->setSize(m_button_width,m_button_height);
    exit_button->setPosition(m_half_window_width - (m_button_width / 2.0f),650);
    exit_button->setInheritedOpacity(0.8f);
    exit_button->setTextSize(35u);
    exit_button->connect("pressed",[&]() 
    { 
        m_game->get_render_window().close(); 
    });
    m_gui.add(exit_button);
}