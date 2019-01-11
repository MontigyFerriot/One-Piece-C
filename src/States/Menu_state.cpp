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

#include <iostream>

Menu_state::Menu_state(Game* game)
        :State{game},
         m_gui{game->get_render_window()},
         m_button_width{240.0f},
         m_button_height{60.0f},
         m_background_number{2},
         m_logo{m_resource_manager,"one_piece_logo.png"},
         m_background1{m_resource_manager,"ace_background.png"},
         m_background2{m_resource_manager,"luffy_gear_second.png"},
         m_main_animation{&m_ace_background_animation},
         //m_back_animation{&m_luffy_gear_second_animation},
         m_background{&m_background1},
         m_back_background{&m_background2},
         m_background_switching{true},
         m_init_switching{true},
         m_ace_background_animation{Function_animation{0, 0, 200, 1, game->get_win_width(),
            game->get_win_height(), 0.05f, []( int& x, int& y) { x+=1; }}},
         m_katakuri_background_animation{Function_animation{0, 0, 1, 1400 ,game->get_win_width(),
            game->get_win_height(), 0.05f, []( int& x, int& y) { y+=1; }}},
         m_strawhats_animation{Function_animation{0, 0, 200, 1050, game->get_win_width(),
            game->get_win_height(), 0.05f, []( int& x, int& y) { x+=1; y+=1; }}},
         m_luffy_gear_second_animation{Function_animation{0, 0, 1, 315, game->get_win_width(),
            game->get_win_height(), 0.05f, []( int& x, int& y) { y+=1; }}},
         m_fading{Fade_animation{}}
{
        m_logo.get_sprite().setPosition(308.0f, -100.0f);

        m_background->get_sprite().setPosition(0.0f, 0.0f);

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
                m_music_player.play();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                m_music_player.stop();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
                m_music_player.next(clocked_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
                m_music_player.previous(clocked_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T))
                m_music_player.restart(clocked_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y))
                m_music_player.shuffle_play(clocked_time);
}

void Menu_state::update(float dt, float clocked_time) 
{
        if (m_background_switching) 
        {
                if (m_init_switching) 
                {
                        std::cout << "Switching\n";
                        init_switching(clocked_time);
                        m_init_switching = false;
                }

                std::cout << "Main: " << static_cast<int>(m_background->get_sprite().getColor().a) << "\n";
                m_fading.animate(clocked_time, m_background->get_sprite());
                m_back_animation->animate(clocked_time, m_back_background->get_sprite());
                std::cout << "Back: " << static_cast<int>(m_back_background->get_sprite().getColor().a) << "\n";
                m_back_fading.animate(clocked_time, m_back_background->get_sprite());

                if (m_back_animation->get_animation().is_end()) 
                {
                        m_back_animation->get_animation().restart();
                        m_background_switching = false;
                }
        }

        m_main_animation->animate(clocked_time, m_background->get_sprite());
        if (0.6f * m_main_animation->get_animation().time_of_animation() < clocked_time - m_main_anim_old_time)
        {
                std::cout << "that fucking condition is right" << std::endl;
                m_background_switching = true;
                m_init_switching = true;
        }
        
        //m_music_player.check_to_switch(clocked_time); // TODO: Make switching to next music when one ends.
}


void Menu_state::draw()
{
        if (m_background_switching)
                m_back_background->draw(m_game->get_render_window());
        m_background->draw(m_game->get_render_window());
                m_back_background->draw(m_game->get_render_window());
        m_logo.draw(m_game->get_render_window());
        m_gui.draw();
}

void Menu_state::init_switching(float clocked_time)
{
        int c;

        while ((c = util::randomize(1,4)) == m_background_number);
        m_background_number = c;

        switch (c)
        {
                case 1:
                        switch_backgrounds(clocked_time, "katakuri_background.png", m_katakuri_background_animation);
                break;
                case 2:
                        switch_backgrounds(clocked_time, "ace_background.png", m_ace_background_animation);
                break;
                case 3:
                        switch_backgrounds(clocked_time, "strawhats1.png", m_strawhats_animation);
                break;
                case 4:
                        switch_backgrounds(clocked_time, "luffy_gear_second.png", m_luffy_gear_second_animation);
                break;
                default:
                        switch_backgrounds(clocked_time, "katakuri_background.png", m_katakuri_background_animation);
        }
}

void Menu_state::switch_backgrounds(float clocked_time, const std::string& texture_name, 
        Animation_launcher<Function_animation>& anim)
{
        sf::Color p;
        float x;

        x = 0.75f * anim.get_animation().time_of_animation() / 256.f;
        p = m_background->get_sprite().getColor();

        std::swap(m_background, m_back_background); 

        m_back_animation = m_main_animation; 
        m_back_fading = Fade_animation{x - 0.5f, 255, 4, 4};

        m_fading = Fade_animation{x - 0.5f, 4, 255, 4};
        m_background->get_sprite().setTexture(m_resource_manager.get_texture(texture_name));
        m_main_animation = &anim;

        p.a = 0;
        m_background->get_sprite().setColor(p);
        m_main_anim_old_time = clocked_time;
}

void Menu_state::set_up_gui()
{   
        tgui::Button::Ptr play_button = tgui::Button::create(sf::String("Play Game"));
        play_button->setSize(m_button_width, m_button_height);
        play_button->setPosition(m_half_window_width - (m_button_width / 2.0f), 450);
        play_button->setInheritedOpacity(0.8f);
        play_button->setTextSize(35u);
        play_button->connect("pressed",[&]() 
        { 
            m_game->change_state(new Play_state{m_game}); 
        });
        m_gui.add(play_button);
        
        tgui::Button::Ptr option_button = tgui::Button::create(sf::String("Options"));
        option_button->setSize(m_button_width, m_button_height);
        option_button->setPosition(m_half_window_width - (m_button_width / 2.0f), 550);
        option_button->setInheritedOpacity(0.8f);
        option_button->setTextSize(35u);
        option_button->setEnabled(true);
        m_gui.add(option_button);
        
        tgui::Button::Ptr exit_button = tgui::Button::create(sf::String("Exit"));
        exit_button->setSize(m_button_width, m_button_height);
        exit_button->setPosition(m_half_window_width - (m_button_width / 2.0f), 650);
        exit_button->setInheritedOpacity(0.8f);
        exit_button->setTextSize(35u);
        exit_button->connect("pressed",[&]() 
        { 
            m_game->get_render_window().close(); 
        });
        m_gui.add(exit_button);
}
