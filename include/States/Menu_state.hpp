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

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <iostream>

#include "SFML/Graphics.hpp"
#include <TGUI/TGUI.hpp>
#include "State_base.hpp"
#include "Animations/Function_animation.hpp"
#include "Utility.hpp"
#include "Objects/Object.hpp"

class Game;
class Menu_state : public State
{ 
    public:
        explicit Menu_state(Game* game);

        ~Menu_state();
    private:
        // void some_logic();

        void input(float dt, float clocked_time);
        void update(float dt, float clocked_time);
        void draw();
        void set_up_gui();
        void switch_to_next_background();

    private:
        tgui::Gui m_gui;

        const float m_button_width;
        const float m_button_height;

        Object m_logo;
        Object m_background;

        Function_animation<>* m_main_animation;
        int m_background_number;

        Function_animation<> m_ace_background_animation;
        Function_animation<> m_katakuri_background_animation;
        Function_animation<> m_strawhats_animation;
        Function_animation<> m_luffy_gear_second_animation;
};

#endif // MENU_STATE_H