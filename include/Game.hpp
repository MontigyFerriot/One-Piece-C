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

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Resource_manager.hpp"
#include "Music_player.hpp"

class State; // forward declaration needed to use state
class Game
{
    public: 
        Game();
                
        // main logic function. It runs main loop of the program.
        // manages time and states
        void run_main_loop();

        // changes current state
        void change_state(State* state);

        // return window's measure
        int get_win_width() const;
        int get_win_height() const;

        // returns reference to resource_manager
        Resource_manager& get_resource_manager();
        
        // returns reference to music_player
        Music_player& get_music_player();

        // returns reference to event 
        sf::Event& get_event();

        // returns reference to render_window
        sf::RenderWindow& get_render_window();
    private:
        // handles all window events
        void window_event();

        // display number of frames per second. WIP
        void display_fps(float current_time);  

    private:
        sf::RenderWindow m_window; // window of the game
        static constexpr int m_win_width = 1366; // width of the window
        static constexpr int m_win_height = 768; // height of the window

        std::shared_ptr<State> m_state; // pointer to current state 

        Resource_manager m_resource_manager; // default Resource_manager
        Music_player m_music_player;

        sf::Event m_event;

        sf::Text m_frames_per_second; // sf::Text which shows current frames rate
        sf::Font m_arial; // font used in the program 

        float m_last_time; // holds time of last
};

#endif // GAME_H