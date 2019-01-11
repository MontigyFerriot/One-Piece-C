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

#ifndef STATE_BASE_H
#define STATE_BASE_H

#include <memory>
#include "Resource_manager.hpp"
#include "Music_player.hpp"

class Game;
class State
{
    public:
        // main logic function
        void logic(float dt, float clocked_time);

        // logic pure virtual functions 
        virtual void input(float dt, float clocked_time) = 0;
        virtual void update(float dt, float clocked_time) = 0;
        virtual void draw() = 0;

        State(const State& another) = delete;
        State() = delete;
        void operator=(const State& another) = delete;
    protected:
        explicit State(Game* game); 
    protected:
        Game* m_game;
        Resource_manager& m_resource_manager;
        Music_player& m_music_player;

        // constants
        const float m_window_width;
        const float m_window_height;

        const float m_half_window_width;
        const float m_half_window_height;
};

#endif // STATE_BASE_H